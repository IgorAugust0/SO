/*
 * Exemplo que alterna uso de file descriptor e streams.
 */
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  FILE* f;
  char c;
  
  f = fopen ("teste.txt", "r");

  if (read(f->_fileno, &c, 1)) {
    printf("Caracter lido via file descriptor = %c\n", c);
  }
  
  while (fscanf(f, "%c", &c) != EOF)
    printf("%c", c);
  fclose(f);  
  return 0;

}
