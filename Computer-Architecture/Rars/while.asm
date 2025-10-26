.text
.globl _start

_start:
    li s1, 0          # contador
    li a2, 0          # acumulador

while:
    li s2, 20
    beq s1, s2, store_value
    addi s1, s1, 1
    addi a2, a2, 9
    j while

store_value:
    addi sp, sp, -4   # aloca espaço na pilha
    sw a2, 0(sp)      # armazena o valor acumulado (a2) na pilha

end_program:
    lw a0, 0(sp)       # carrega o valor da pilha para a0
    addi sp, sp, 4     # desaloca espaço da pilha (boa prática)

    li a7, 1           # syscall 1: imprimir inteiro
    ecall              # imprime a0 no console

    li a7, 93          # syscall 93: sair do programa
    ecall


