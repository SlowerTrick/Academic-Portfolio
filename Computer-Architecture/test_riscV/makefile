default:
	clear
	rm -rf *.o *.exe
	riscv64-linux-gnu-as while.s -o while.o
	riscv64-linux-gnu-gcc -o while while.o -nostdlib -static
	./while
# .PHONY: all

#%:
#	rm -rf *.o
#	riscv64-linux-gnu-as $@.s -o $@.o
#	riscv64-linux-gnu-gcc -o $@ $@.o -nostdlib -static
#	./$@
