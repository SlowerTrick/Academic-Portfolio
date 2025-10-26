.data
	string: .asciiz "Hello, World!"
	
.macro print_string(%x)
	li $v0, 4
	la $a0, %x
	syscall
.end_macro

.macro end_program()
	li $v0, 10
	li $a0, 0
	syscall
.end_macro
	

.text
.globl _start
_start:
	print_string(string)
	end_program()
