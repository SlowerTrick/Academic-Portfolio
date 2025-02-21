find ../../Gabarito-obj -name "*.o*" ! -iname "*vector*" | xargs gcc -g vector.c
./test < ../../Casos/1/entrada.txt > saida.txt