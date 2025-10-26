.section .text
.global _start

_start:
    li a1, 0

    while:
        li t1, 20
        beq t1, a1, store_value
        j while
    
    j end_program

store_value:
    sw t1, 0(s1)

end_program:
    # Encerrar o programa
    lw t1, 0(s1) # código de saída
    li a7, 93         # syscall número 93 (exit)
    ecall