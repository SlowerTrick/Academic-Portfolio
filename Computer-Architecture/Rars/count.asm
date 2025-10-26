.data
	value: .byte 50

.text
.globl _start

_start:
	la t0, value
	lb t0, 0(t0)
	li t1, 0
	
	while:
		li a7, 1
		mv a0, t1 					# Syscall print a0 (numero)
		ecall
		
		li a7, 11
		li a0, '\n'					# Syscall print a0 ('\n')
		ecall
		
		beq t0, t1, end_program
		addi t1, t1, 1
		j while

end_program:
	li a7, 93
	li a0, 0						# Syscall exit		
	ecall