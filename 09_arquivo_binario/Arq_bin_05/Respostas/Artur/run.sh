find ../../Gabarito-obj/ -name "*.o*" ! -name "*estabelecimento*" | xargs gcc -o test estabelecimento.c
./test < ../../test.txt > out.txt
diff out.txt ../../Casos/1/saida/saida.txt