find ../../Gabarito-obj/ -name "*.o*" ! -name "*main*" | xargs gcc -o test main.c
./test < ../../test.txt > out.txt
diff out.txt ../../Casos/1/saida/saida.txt