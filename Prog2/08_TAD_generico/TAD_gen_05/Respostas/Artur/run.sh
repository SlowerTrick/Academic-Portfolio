find ../../Gabarito-obj/ -name "*.o*" ! -name "*agendatarefas*" | xargs gcc -o test agendatarefas.c
./test < ../../Casos/4/entrada.txt > out.txt
#valgrind ./test < ../../Casos/4/entrada.txt > out.txt
diff out.txt ../../Casos/4/saida/saida.txt