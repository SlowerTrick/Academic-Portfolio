#!/bin/bash

# Diretório de entrada
input_dir="input"
output_dir="output"
outprog_dir="outprog"

# Loop para executar o programa e comparar a saída
for input_file in $input_dir/*
do
    # Extrai o nome base do arquivo de teste
    base_name=$(basename $input_file)

    # Executa o programa e redireciona a saída
    ./prog < $input_dir/$base_name > $outprog_dir/$base_name

    # Compara a saída do programa com a saída esperada
    diff $output_dir/$base_name $outprog_dir/$base_name
done