#include <stdlib.h>
#include <stdio.h>

int main(){
  int nr;
  FILE *f =fopen("numbers.txt", "r");
  while (fscanf(f , "%d", &nr)>0) {
    printf("%d", nr);
  }
}
