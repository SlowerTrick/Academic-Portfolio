#include <stdio.h>

double LeNotasECalculaMediaAluno ();
int ContaAlunosAprovadosTurma ();


int main (void)
{
    int turma = 0, alunos = 0, i = 0, j = 0, melhorturma = 0, piorturma = 0, contador = 0, maiorcontador = 0, piorcontador = -1;
    scanf ("%i", &turma);

    for (i = 0; i < turma; i++)
    {
        printf ("TURMA:%i\n", i+1);
        scanf("%i", &alunos);
        getchar();
        for (j = 0; j < alunos; j++)
        {
            char letra1 = 0, letra2 = 0, abertura = 0;
            scanf ("%c%c%c", &letra1, &letra2, &abertura);

            double media = ContaAlunosAprovadosTurma ();

            if (media >= 70)
            {
                printf ("%c\n", letra1);
                contador++;
            }
        }
        if (contador > maiorcontador)
        {
            maiorcontador = contador;
            melhorturma = i+1;
        }
        if (contador < piorcontador || piorcontador == -1)
        {
            piorcontador = contador;
            piorturma = i+1;
        }
        contador = 0;
    }
    printf ("MAIOR:TURMA %i MENOR:TURMA %i\n", melhorturma, piorturma);
}

int ContaAlunosAprovadosTurma ()
{
    char fechamento = 0;
    int nota = 0, menornota = 101, contador = 0;
    double somatorio = 0;

    while (1)
    {
        scanf("%i", &nota);
        if (nota < menornota)
        {
            menornota = nota;
        }
        somatorio += nota;
        contador++;

        scanf("%c", &fechamento);
        if (fechamento == ']')
        {
            getchar();
            break;
        }
    }

    if (contador > 1)
    {
        contador--;
        float final = (somatorio - menornota) / contador;
        return final;
    }
    else
    {
        return somatorio;
    }
}