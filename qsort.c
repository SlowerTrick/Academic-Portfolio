#include <stdio.h>
#include <stdlib.h>

int sort_array(const void *x, const void *y);

int main(void)
{
    int array[10] = {7, 4, 3, 1, 8, 2, 9, 5, 0, 6};
    
    printf("Array Inicial:\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", array[i]);
    printf("\n\n");

    qsort(array, 10, sizeof(int), sort_array);

    printf("Array Final:\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}

int sort_array(const void *x, const void *y)
{
    return (*(int*)x - *(int*)y);
}