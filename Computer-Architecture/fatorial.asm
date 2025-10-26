.text
.globl _start
_start:
	loop:
		jal read_input
		jal fat
		jal play_again
		beq $v0, $zero, exit
		j loop

read_input:
	li $v0, 5
	syscall
	jr $ra

write_output:
	li $v0, 1
	addi $a0, $t0, 0
	syscall
	jr $ra

fat:
	bltz $v0, return_fat
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	addi $t0, $v0, 0
	addi $t1, $v0, -1
	while:
		mul $t0, $t0, $t1
		addi $t1, $t1, -1
		blez $t1, return_fat
		j while

return_fat:
	jal write_output
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra
	

play_again:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read_input
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	seq $v0, $v0, $zero
	xori $v0, $v0, 1
	jr $ra 

exit:
	li $v0, 10
	li $a0, 0
	syscall
