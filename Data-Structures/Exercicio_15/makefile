all:
	clear
	gcc -o test *.c

test: all
	./test

valgrind: all
	valgrind ./test

debug:
	clear
	gcc -g *.c
