#find ../../Gabarito-obj/ -name "*.o*" ! -name "*fila*" | xargs gcc -o test fila.c
#./test < ../../Casos/3/entrada.txt > out.txt
#diff out.txt ../../Casos/3/saida/saida.txt

gcc -o test *.c
./test  < ../../Casos/5/entrada.txt > out.txt
diff out.txt ../../Casos/5/saida/saida.txt