#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime_vetor(int tam, int *v);
void buble_sort(int tam, int *v);
void quick_sort(int tam, int *v);
int linear_search(int tam, int *v, int valor);
int binary_search(int tam, int *v, int valor);

int main(void)
{
    srand(time(NULL));

    time_t incio, fim;
    time(&incio);

    int tam_vetor = 100000;
    int vet[tam_vetor];

    int min = 0;
    int max = 100000;
    for (int i = 0; i < tam_vetor; i++)
    {
        int random = (rand() % (max - min + 1)) + min;
        vet[i] = random;
    }

    quick_sort(tam_vetor, vet);

    int valor_buscado = rand() % (max - min + 1) + min;
    int idx_valor_buscado = linear_search(tam_vetor, vet, valor_buscado);

    if (idx_valor_buscado >= 0)
        printf("Valor buscado: %d, Idx do valor: %d, Valor no vetor: %d\n", valor_buscado, idx_valor_buscado, vet[idx_valor_buscado]);
    else
        printf("Valor nao encontrado\n");

    time(&fim);
    double tempo = difftime(fim, incio);
    printf("Tempo em segundos: %lf\n", tempo);
    printf("Tempo em minutos: %lf\n", tempo / 60);

    return 0;
}

void imprime_vetor(int tam, int *v)
{
    for (int i = 0; i < tam; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void buble_sort(int tam, int *v)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (v[i] > v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void quick_sort(int tam, int *v)
{
    if (tam <= 1)
        return;
    int x = v[0];
    int a = 1;
    int b = tam - 1;
    do
    {
        while (a < tam && v[a] <= x)
            a++;
        while (v[b] > x)
            b--;
        if (a < b)
        {
            int aux = v[a];
            v[a] = v[b];
            v[b] = aux;
        }
    } while (a <= b);

    v[0] = v[b];
    v[b] = x;

    quick_sort(b, v);
    quick_sort(tam - a, &v[a]);
}

int linear_search(int tam, int *v, int valor)
{
    for (int i = 0; i < tam; i++)
        if (v[i] == valor)
            return i;
    return -1;
}

int binary_search(int tam, int *v, int valor)
{
    int low = 0, high = tam - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] == valor)
            return mid;
        if (v[mid] < valor)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}