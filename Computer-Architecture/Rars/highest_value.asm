.data
array: .word 5, 100, 1, 49, -1   # -1 indica o fim do array

.text
.globl _start

_start:
    la a2, array
    j check_array_size

check_array_size:
    li a3, 0            # Inicializa contador de tamanho
    while_1:
        slli t0, a3, 2   # Calcula offset
        add t1, a2, t0   # Calcula endereço do elemento
        lw t4, 0(t1)     # Carrega elemento
        
        li t5, -1
        beq t4, t5, check_highest_value
        addi a3, a3, 1    # Incrementa contador
        j while_1

check_highest_value:
    li s0, 0             # Inicializa índice
    li a0, -2147483648   # Inicializa maior valor com mínimo inteiro possível
    while_2:
        slli t1, s0, 2    # Calcula offset
        add t1, a2, t1    # Calcula endereço do elemento
        lw s1, 0(t1)      # Carrega elemento
        
        li t0, -1         # Verifica se é o marcador de fim
        beq s1, t0, end_program
        
        ble s1, a0, else  # Se não for maior, pula
        mv a0, s1         # Atualiza maior valor
        mv a1, t1         # Atualiza endereço do maior valor
    else:
        addi s0, s0, 1     # Incrementa índice
        j while_2

end_program:
    li a7, 93
    li a0, 0
    ecall