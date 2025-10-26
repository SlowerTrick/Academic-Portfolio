all:
	clear
	gcc -o test *.c

test: all
	./test

valgrind:
	clear
	gcc -o test *.c
	valgrind --leak-check=full --show-leak-kinds=all ./test

gdb:
	clear
	gcc -g *.c
	gdb ./test
