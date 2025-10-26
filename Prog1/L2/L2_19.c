#include <stdio.h>

int main (void)
{
    int delegacao = 0, melhorMasculino = 0, melhorFeminino = 0, piorFeminino = 0, piorMasculino = 0;
    int nota1 = 0, nota2 = 0, nota3 = 0;
    int somatorioM = 0, somatorioF = 0, indexsomatorioM = 0, indexsomatorioF = 0, maiorsomatorioM = 0, maiorsomatorioF = 0;
    int melhornotaM1 = 0, melhornotaM2 = 0, melhornotaM3 = 0;
    int melhornotaF1 = 0, melhornotaF2 = 0, melhornotaF3 = 0;
    int piornotaM1 = 10, piornotaM2 = 10, piornotaM3 = 10;
    int piornotaF1 = 10, piornotaF2 = 10, piornotaF3 = 10;
    char genero = 0;
    int index = 0, contador = 0, i = 0, j = 0;

    scanf("%i", &delegacao);

    while (contador < delegacao)
    {
        while (1)
        {
            scanf("%i", &index);
            if (index == -1)
            {
                break;
            }

            scanf("%c", &genero);
            if (genero == 'M')
            {
                scanf("%i%i%i", &nota1, &nota2, &nota3);

                for (i = 0; i < 2; i++)
                {
                    if (nota3 > nota2)
                    {
                        int aux = nota3;
                        nota3 = nota2;
                        nota2 = aux;
                    }
                    if (nota2 > nota1)
                    {
                        int aux = nota2;
                        nota2 = nota1;
                        nota1 = aux;
                    }
                }
                somatorioM += nota1;

                if (nota1 > melhornotaM1)
                {
                    melhornotaM1 = nota1;
                    melhornotaM2 = nota2;
                    melhornotaM3 = nota3;
                    melhorMasculino = index;
                }

                if (nota1 == melhornotaM1)
                {
                    if (nota2 > melhornotaM2)
                    {
                        melhornotaM1 = nota1;
                        melhornotaM2 = nota2;
                        melhorMasculino = index;
                    }
                }

                if (nota1 == melhornotaM1 && nota2 == melhornotaM2)
                {
                    if (nota3 > melhornotaM3)
                    {
                        melhornotaM1 = nota1;
                        melhornotaM2 = nota2;
                        melhornotaM3 = nota3;
                        melhorMasculino = index;
                    }
                }
                //Pior nota
                if (nota1 < piornotaM1)
                {
                    piornotaM1 = nota1;
                    piornotaM2 = nota2;
                    piornotaM3 = nota3;
                    piorMasculino = index;
                }
                else if (nota1 == piornotaM1)
                {
                    if (nota2 < piornotaM2)
                    {
                        piornotaM2 = nota2;
                        piorMasculino = index;
                    }
                    else if (nota2 == piornotaM2)
                    {
                        if (nota3 < piornotaM3)
                        {
                            piornotaM3 = nota3;
                            piorMasculino = index;
                        }
                        else if (nota3 == piornotaM3)
                        {
                            if (index > piorMasculino)
                            {
                                piorMasculino = index;
                            }
                        }
                    }
                }
            }

            if (genero == 'F')
            {
                scanf("%i%i%i", &nota1, &nota2, &nota3);

                for (i = 0; i < 2; i++)
                {
                    if (nota3 > nota2)
                    {
                        int aux = nota3;
                        nota3 = nota2;
                        nota2 = aux;
                    }
                    if (nota2 > nota1)
                    {
                        int aux = nota2;
                        nota2 = nota1;
                        nota1 = aux;
                    }
                }
                somatorioF += nota1;

                if (nota1 > melhornotaF1)
                {
                    melhornotaF1 = nota1;
                    melhornotaF2 = nota2;
                    melhornotaF3 = nota3;
                    melhorFeminino = index;
                }

                if (nota1 == melhornotaF1)
                {
                    if (nota2 > melhornotaF2)
                    {
                        melhornotaF1 = nota1;
                        melhornotaF2 = nota2;
                        melhorFeminino = index;
                    }
                }

                if (nota1 == melhornotaF1 && nota2 == melhornotaF2)
                {
                    if (nota3 > melhornotaF3)
                    {
                        melhornotaF1 = nota1;
                        melhornotaF2 = nota2;
                        melhornotaF3 = nota3;
                        melhorFeminino = index;
                    }
                }
                if (nota1 < piornotaF1)
                {
                    piornotaF1 = nota1;
                    piornotaF2 = nota2;
                    piornotaF3 = nota3;
                    piorFeminino = index;
                }
                else if (nota1 == piornotaF1)
                {
                    if (nota2 < piornotaF2)
                    {
                        piornotaF2 = nota2;
                        piorFeminino = index;
                    }
                    else if (nota2 == piornotaF2)
                    {
                        if (nota3 < piornotaF3)
                        {
                            piornotaF3 = nota3;
                            piorFeminino = index;
                        }
                        else if (nota3 == piornotaF3)
                        {
                            if (index > piorFeminino)
                            {
                                piorFeminino = index;
                            }
                        }
                    }
                }
            }
        }
        if (somatorioM > maiorsomatorioM)
        {
            maiorsomatorioM = somatorioM;
            indexsomatorioM = contador + 1;
        }

        if (somatorioF > maiorsomatorioF)
        {
            maiorsomatorioF = somatorioF;
            indexsomatorioF = contador + 1;
        }

        printf ("MELHORES ATLETAS DA DELEGACAO %i\n", contador+1);
        printf ("MASCULINO: %i FEMININO: %i\n", melhorMasculino, melhorFeminino);
        printf ("PIORES ATLETAS DA DELEGACAO %i\n", contador+1);
        printf ("MASCULINO: %i FEMININO: %i\n\n", piorMasculino, piorFeminino);
        melhornotaM1 = 0;
        melhornotaM2 = 0;
        melhornotaM3 = 0;
        melhornotaF1 = 0;
        melhornotaF2 = 0;
        melhornotaF3 = 0;
        piornotaM1 = 10;
        piornotaM2 = 10;
        piornotaM3 = 10;
        piornotaF1 = 10;
        piornotaF2 = 10;
        piornotaF3 = 10;
        somatorioM = 0;
        somatorioF = 0;
        contador++;
    }
    printf ("DELEGACAO CAMPEA:\n");
    printf ("MASCULINO: %i FEMININO: %i", indexsomatorioM, indexsomatorioF);
    return 0;
}