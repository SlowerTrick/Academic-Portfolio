all:
	clear
	gcc -o test *.c
	./test

debug:
	clear
	gcc -g *.c
	gdb ./a.out

valgrind:
	clear
	gcc -o test *.c
	valgrind ./test