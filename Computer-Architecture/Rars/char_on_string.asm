.data
	string: .asciz "Steins;Gate"
	wanted_char: .byte 'G'

.text
.globl _start

_start:
	la a0, string
	la a1, wanted_char
	lb a1, 0(a1)
	j check_string
	
check_string:
	while:
		lb t2, 0(a0)
		beq t2, zero, wanted_value_not_found
		beq t2, a1, wanted_value_found
		
		addi a0, a0, 1
		j while

wanted_value_found:
	j end_program

wanted_value_not_found:
	li a0, 0
	j end_program
		
end_program:
	li a7, 93
	li a0, 0
	ecall