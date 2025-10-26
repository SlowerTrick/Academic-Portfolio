.data
	input_fatorial:         .asciz "Escolha um numero para o calculo do fatorial: "
	tam_input_fatorial:     .word 47
	
	input_play_again:       .asciz "Voce quer calcular novamente (0 para nao e 1 para sim)? "
	tam_input_play_again:   .word 58
	
	resultado_fatorial:     .asciz "O resultado do fatorial eh: "
	tam_resultado_fatorial: .word 31
	
	input_error:			.asciz "Erro no input! tente novamente"
	tam_input_error:    	.word 31

	newline:                .asciz "\n"

# ======================
# == MACROS DE SAÍDA ==
# ======================

.macro print_str(%msg, %len)
    li a7, 64
    li a0, 1
    la a1, %msg             # Syscall print string
    lw a2, %len
    ecall
.end_macro

.macro print_newline()
    li a7, 64
    li a0, 1                # Syscall print string
    la a1, newline
    li a2, 1
    ecall
.end_macro

.macro print_result()
	mv a1, t1
	li a7, 1				   								# Syscall print integer
	mv a0, a1
	ecall
.end_macro

.text
.globl _start

_start:
loop:
	jal read_fatorial          								# Le número (retorno em a0)
	jal fatorial               								# Calcula fatorial (retorno em a0)
	jal play_again             								# Pergunta se deseja continuar (retorno em a0)
	beq a0, zero, end_program  								# Se resposta for 0, encerra
	j loop

read_fatorial:
	print_str input_fatorial, tam_input_fatorial
	li a7, 5        										# Syscall read integer
	ecall
	ret

play_again:
	print_str input_play_again, tam_input_play_again
	li a7, 5        										# Syscall read integer
	ecall
	ret

fatorial:
	mv t0, a0       										# Número original
	li t1, 1        										# Acumulador do resultado
	li t2, 1        										# Condição de parada
	
	bltz a0, erro_input
	beq t0, zero, finish_fat
	while:
		beq t0, t2, finish_fat
		mul t1, t1, t0
		addi t0, t0, -1
		j while

erro_input:
	print_str input_error, tam_input_error
	print_newline
	ret

finish_fat:
	print_str resultado_fatorial, tam_resultado_fatorial
	print_result
	print_newline

	mv a0, a1       										# Retorna valor do fatorial em a0
	ret

end_program:
	li a7, 93        										# Syscall exit
	li a0, 0
	ecall
