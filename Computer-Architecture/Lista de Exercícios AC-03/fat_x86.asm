section .data
    input_fatorial:         db "Escolha um numero para o calculo do fatorial: ", 0
    tam_input_fatorial:     equ $ - input_fatorial

    input_play_again:       db "Voce quer calcular novamente (0 para nao e 1 para sim)? ", 0
    tam_input_play_again:   equ $ - input_play_again

    resultado_fatorial:     db "O resultado do fatorial eh: ", 0
    tam_resultado_fatorial: equ $ - resultado_fatorial

    input_error:            db "Erro no input! tente novamente", 0
    tam_input_error:        equ $ - input_error

    newline:                db 10

section .bss
    num_buffer resb 32          ; Buffer para conversão de número para string
    result     resd 1           ; Para armazenar o resultado

section .text
    global _start

; ======================
; == MACROS DE SAÍDA ==
; ======================
%macro print_str 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 0x80
%endmacro

%macro print_newline 0
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80
%endmacro

%macro print_result 0
    mov eax, [result]
    mov edi, num_buffer
    call int_to_string
    mov edx, ecx        ; Tamanho da string
    mov ecx, num_buffer
    mov eax, 4
    mov ebx, 1
    int 0x80
%endmacro

; ======================
; == PROGRAMA PRINCIPAL ==
; ======================

_start:
    jmp loop

loop:
    call read_fatorial
    call fatorial
    call play_again
    cmp eax, 0
    je end_program
    jmp loop

; ======================
; == LEITURA DE INPUT ==
; ======================

read_fatorial:
    print_str input_fatorial, tam_input_fatorial
    mov eax, 3
    mov ebx, 0
    mov ecx, num_buffer
    mov edx, 32
    int 0x80
    mov esi, num_buffer
    call string_to_int
    ret

play_again:
    print_str input_play_again, tam_input_play_again
    mov eax, 3
    mov ebx, 0
    mov ecx, num_buffer
    mov edx, 32
    int 0x80
    mov esi, num_buffer
    call string_to_int
    ret

; ======================
; == FUNÇÃO FATORIAL ==
; ======================

fatorial:
    cmp eax, 0
    jl erro_input
    mov ecx, eax        ; Número original
    mov ebx, 1          ; Acumulador

.loop_fat:
    cmp ecx, 1
    jl .fim
    imul ebx, ecx
    dec ecx
    jmp .loop_fat

.fim:
    mov [result], ebx
    print_str resultado_fatorial, tam_resultado_fatorial
    print_result
    print_newline
    mov eax, ebx        ; Retorna o resultado
    ret

erro_input:
    print_str input_error, tam_input_error
    print_newline
    mov eax, 0
    ret

; ======================
; == SAIR DO PROGRAMA ==
; ======================

end_program:
    mov eax, 1
    xor ebx, ebx
    int 0x80

; ======================
; == CONVERSÕES AUXILIARES ==
; ======================

; string_to_int:
; Entrada: ESI aponta para string
; Saída: EAX = valor inteiro
string_to_int:
    xor eax, eax
    xor ecx, ecx
.proximo:
    movzx edx, byte [esi + ecx]
    cmp dl, 10         ; ignora '\n'
    je .fim
    cmp dl, '0'
    jb .fim
    cmp dl, '9'
    ja .fim
    sub dl, '0'
    imul eax, eax, 10
    add eax, edx
    inc ecx
    jmp .proximo
.fim:
    ret

; int_to_string:
; Entrada: EAX = número, EDI = buffer
; Saída: ECX = tamanho da string
int_to_string:
    mov ebx, 10
    xor ecx, ecx
    test eax, eax
    jnz .convert
    mov byte [edi], '0'
    mov ecx, 1
    ret

.convert:
    xor edx, edx
.push_loop:
    xor edx, edx
    div ebx
    add dl, '0'
    push dx
    inc ecx
    test eax, eax
    jnz .push_loop

    ; agora desempilha
    mov eax, ecx
    mov ecx, eax
.pop_loop:
    pop dx
    mov [edi], dl
    inc edi
    dec eax
    jnz .pop_loop
    ret
