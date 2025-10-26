.section .text
.global _start

_start:
    # Syswrite hello world
    addi a7, zero, 64
    addi a0, zero, 1
    la a1, hello_world
    addi a2, zero, 9
    ecall

    # Sysexit
    addi a7, zero, 93
    addi a0, zero, 69
    ecall

hello_world:
    .ascii "1048596!\n"
