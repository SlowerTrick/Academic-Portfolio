#include <stdio.h>

int main(void) 
{
    int debito = 0, presc = 0, tempo = 0, somatorio = 0;
    char a = 0, b = 0, c = 0;
    char abertura = 0, fechamento = 0, doispontos = 0;
    int maior = 0, l1 = 0, l2 = 0, l3 = 0, ignorar = 0;
    int total = 0;

    scanf ("%i", &ignorar);
    getchar();

    while (scanf("%d", &presc) != EOF) 
    { // Loop até o fim do arquivo
        getchar(); // Consome o newline após o número

        maior = 0; // Reseta o maior débito para o novo conjunto de dados
        l1 = l2 = l3 = 0; // Reseta as placas para o novo conjunto de dados

        while (1) 
        {
            somatorio = 0; // Reseta o somatório para a nova placa
            abertura = fechamento = doispontos = 0; // Reseta os caracteres de controle

            scanf("%c%c%c", &a, &b, &c); // Lê a placa
            if (a == 'F' && b == 'I' && c == 'M') 
            {
                break; // Se for FIM, termina o processamento do conjunto atual
            }

            while (1) 
            {
                scanf("%c", &abertura);
                if (abertura == '\n' || abertura == EOF) 
                {
                    break; // Se for o fim da linha ou do arquivo, termina o loop
                }
                if (abertura != '(') 
                {
                    continue; // Se não for '(', ignora e lê o próximo caractere
                }
                scanf("%i%c%i", &debito, &doispontos, &tempo); // Lê o débito e o tempo
                scanf("%c", &fechamento); // Lê o caractere de fechamento ')'

                if (tempo <= presc) 
                {
                    somatorio += debito; // Soma o débito se o tempo for menor ou igual a presc
                }
            }

            if (somatorio > maior) 
            {
                maior = somatorio; // Atualiza o maior débito
                l1 = a; l2 = b; l3 = c; // Atualiza a placa do maior débito
            }
        }

        if (maior > 0) 
        { // Se houver algum débito
            total += maior;
            printf("PLACA:%c%c%c DEBITO:%i\n", l1, l2, l3, maior); // Imprime a placa com o maior débito
        }
        if (maior == 0)
        {
            printf ("SEM DEBITO!\n");
        }
    }
    printf ("SOMA:%i\n", total);
    return 0;
}