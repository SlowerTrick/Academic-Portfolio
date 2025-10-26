find ../../Gabarito-obj/ -name "*.o*" ! -name "*main*" | xargs gcc -o test main.c
./test < ../../Casos/1/entrada.txt > saida.txt
diff saida.txt ../../Casos/1/saida/saida.txt