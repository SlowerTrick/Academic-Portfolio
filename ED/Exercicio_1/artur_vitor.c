#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415

void calc_esfera (float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double* poli, int grau, double x);
int** inverte2 (int n, int* vet);

int main(void)
{
    // Esfera
    float r = 7.7;
    float *area = malloc(sizeof(float));
    float *volume = malloc(sizeof(float));
    calc_esfera(r, area, volume);
    printf("Area: %.2f\nVolume: %.2f\n\n", *area, *volume);

    // Raizes
    float a = 1, b = -1, c = -12;
    float *x1 = malloc(sizeof(float));
    float *x2 = malloc(sizeof(float));
    raizes(a, b, c, x1, x2);
    printf("x1: %.2f\nx2: %.2f\n\n", *x1, *x2);
    
    // Pares
    int tamanho_vet = 10;
    int *vet_pares = malloc(sizeof(int) * tamanho_vet);
    for(int i = 0; i < tamanho_vet; i++)
        vet_pares[i] = i + 1;
    printf("Numero de pares:\n%d\n\n", pares(tamanho_vet, vet_pares));

    // Inverte
    int *vet_inverte = malloc(sizeof(int) * tamanho_vet);
    for (int i = 0; i < tamanho_vet; i++)
        vet_inverte[i] = i + 1;
    inverte(tamanho_vet, vet_inverte);
    printf("Vetor invertido:\n");
    for(int i = 0; i < tamanho_vet; i++)
        printf("%d ", vet_inverte[i]);
    printf("\n\n");
    
    // Polinomio
    int grau = 2;
    double *poli = malloc(sizeof(double) * (grau + 1));
    poli[0] = 12;
    poli[1] = 2;
    poli[2] = 3;
    double x = 2;
    printf("Resultado do polinomio com x = %.2lf:\n%.2lf\n\n", x, avalia(poli, grau, x));

    // Ordena
    int *vet_ordena = malloc(sizeof(int) * tamanho_vet);
    vet_ordena[0] = 3;
    vet_ordena[1] = 7;
    vet_ordena[2] = 0;
    vet_ordena[3] = 2;
    vet_ordena[4] = 9;
    vet_ordena[5] = 4;
    vet_ordena[6] = 6;
    vet_ordena[7] = 1;
    vet_ordena[8] = 8;
    vet_ordena[9] = 5;
    int **vet_ordenado = inverte2(tamanho_vet, vet_ordena);
    
    printf("Vetor ordenado:\n");
    for(int i = 0; i < tamanho_vet; i++)
        printf("%d ", *vet_ordenado[i]);
    printf("\n");

    // Finalizacao do programa
    free(area);
    free(volume);
    free(x1);
    free(x2);
    free(vet_pares);
    free(vet_inverte);
    free(poli);
    free(vet_ordena);
    free(vet_ordenado);
    return 0;
}

void calc_esfera (float r, float* area, float* volume)
{
    *area = 4 * PI * pow(r, 2);
    *volume = 4 * PI * pow(r, 3) / 3;
}

int raizes (float a, float b, float c, float* x1, float* x2)
{
    float delta = pow(b, 2) - 4 * a * c;
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
}

int pares (int n, int* vet)
{
    int total = 0;
    for(int i = 0; i < n; i++)
        if((vet[i] % 2) == 0)
            total++;
    return total;
}

void inverte (int n, int* vet)
{
    for(int i = 0; i < n / 2; i++)
    {
        int aux = vet[i];
        vet[i] = vet[n - i - 1];
        vet[n - i - 1] = aux;
    }
}

double avalia (double* poli, int grau, double x)
{
    double resultado = 0;
    for(int i = 0; i < grau + 1; i++)
        resultado += pow(x, i) * poli[i];
    return resultado;
}

int** inverte2 (int n, int* vet)
{
    int **vet_ordenado = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) 
        vet_ordenado[i] = &vet[i];

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(*vet_ordenado[i] > *vet_ordenado[j])
            {
                int *temp = vet_ordenado[i];
                vet_ordenado[i] = vet_ordenado[j];
                vet_ordenado[j] = temp;
            }
        }
    }
    return vet_ordenado;
}