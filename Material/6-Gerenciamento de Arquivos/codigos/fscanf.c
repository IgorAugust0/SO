/*
 * Cópia de arquivo para a saída padrão.
 */
#include<stdio.h>


int main() {
  FILE* f;
  char c;
  
  f = fopen ("teste.txt", "r");

  while (fscanf(f, "%c", &c) != EOF)
    printf("%c", c);
  fclose(f);  
  return 0;

}
