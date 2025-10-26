find ../../Gabarito-obj/ -name "*.o*" ! -name "*database*" | xargs gcc -o test database.c
./test < ../../test.txt > out.txt
diff out.txt ../../Casos/1/saida/saida.txt