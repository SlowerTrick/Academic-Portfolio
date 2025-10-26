#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} 
tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
int ComparaString(char * str1, char * str2);

int main()
{
    int qtdCand, i = 0, j = 0;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];
    int idsInvalidos[qtdCand];

    for(i = 0; i < qtdCand; i++)
    {
        candidatos[i] = LeCandidato();
    }

    int contadorIdsInvalidos = 0;
    for(i = 0; i < qtdCand - 1; i++)
    {
        int verificador = 0;

        for (j = 0; j < contadorIdsInvalidos; j++)
        {
            if (candidatos[i].codigo == idsInvalidos[j])
            {
                verificador++;
            }
        }
        if (verificador > 0)
        {
            continue;
        }
        for (j = i+1; j < qtdCand; j++)
        {
            if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome))
            {
                if (verificador == 0)
                {
                    ImprimeCandidato(candidatos[i]);
                    verificador++;
                }
                ImprimeCandidato(candidatos[j]);
                idsInvalidos[contadorIdsInvalidos] = candidatos[j].codigo;
                contadorIdsInvalidos++;
            } 
        }
    } 
    return 0; 
}

tCandidato LeCandidato()
{
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato)
{
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", 
    candidato.codigo, candidato.nome, 
    candidato.sobrenome, candidato.nota, candidato.idade);
}

int ComparaString(char * str1, char * str2)
{
    int i = 0;

    // Continue até o final de ambas as strings
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        // Se os caracteres não forem iguais, retorne 0
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    
    // Se ambos chegaram ao final ('\0'), as strings são iguais
    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 1;
    }

    // Se apenas uma das strings chegou ao final, elas não são iguais
    return 0;
}
