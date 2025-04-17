find ../../Gabarito-obj -name "*.o" ! -name "*imagem*" | xargs gcc -o test imagem.c
./test < ../../test.txt > out.txt
#diff out.txt ../../Casos/1/saida/saida.txt