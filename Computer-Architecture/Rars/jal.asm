.text
.globl _start

_start:
	li a0, 400         # Argumento 1
	li a1, 500         # Argumento 2
	jal sum            # Soma a0 com a1, resultado fica em a0

	# Printar a0 (resultado da soma)
	li a7, 1           # Syscall: print integer
	ecall

	# Encerrar programa
	li a7, 93          # Syscall: exit
	li a0, 0           # Código de saída 0
	ecall

# Função de soma
sum:
	add a0, a0, a1     # a0 = a0 + a1
	ret
