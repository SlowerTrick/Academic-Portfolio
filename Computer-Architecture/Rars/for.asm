.data
	increment: .word 30

.text
.globl _start

_start:
	li t1, 0
	li t2, 0
	la t4, increment
	lw t5, 0(t4)
	for:
		li t3, 10
		beq, t1, t3, store_memory
		add t2, t2, t5
		addi t1, t1, 1
		j for

store_memory:
	addi sp, sp, -4
	sw t2, 0(sp)
	j end_program
	
		
end_program:
	addi sp, sp, 4
	li a7, 93
	li a0, 0
	ecall