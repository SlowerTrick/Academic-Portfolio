.section .text
.global _start

_start:
    # Codigo para verificar se um numero é maior que o numero verificador
    li t1, 12                                   # Numero que sera verificado
    li t0, 10                                   # Numero verificador 
    bgt t1, t0, if_block                        # If t1 > t0
    j else_block

if_block:
    addi a7, zero, 64
    addi a0, zero, 1
    la a1, true_string
    addi a2, zero, 5
    ecall
    j end_program

else_block:
    addi a7, zero, 64
    addi a0, zero, 1
    la a1, false_string
    addi a2, zero, 6
    ecall
    j end_program

end_program:
    # Encerrar o programa
    li a0, 0          # código de saída
    li a7, 93         # syscall número 93 (exit)
    ecall

true_string:
    .ascii "True\n"
false_string:
    .ascii "False\n"
