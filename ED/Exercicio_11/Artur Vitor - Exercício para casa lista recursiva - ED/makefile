all:
	clear

test: all
	gcc -o test *.c
	./test

valgrind: all
	gcc -o test *.c
	valgrind ./test

gdb: all
	gcc -g *.c
	gdb ./a.out

