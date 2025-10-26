.section .text
.global _start

_start:
    # Codigo para verici
    li t0, 10


    # Encerrar o programa corretamente
    li a0, 0          # código de saída
    li a7, 93         # syscall número 93 (exit)
    ecall



.section .data
input:
    .ascii "SteinsGate\n"
