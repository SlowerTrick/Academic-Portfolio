all:
	clear
	gcc -o test *.c
	./test

valgrind:
	clear
	gcc -o test *.c
	valgrind --leak-check=full ./test