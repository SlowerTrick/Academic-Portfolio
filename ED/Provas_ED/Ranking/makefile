all:
	clear
	gcc -o test *.c -g

test: all
	./test

gdb: all
	gdb ./a.out

valgrind: all
	valgrind ./test