#include <stdio.h>

int main() {
  int i = 0, den = 0, qtd = 0, cont = 0;

  scanf("%d", &qtd);

  for(i = 2; i <= qtd; i++){
    cont = 0;
    for(den = 1; den <= i; den++){
      if(i % den == 0){
        cont++;
      }
    }
    if(cont == 2)
      printf("%d ", i);
  }

  return 0;
}