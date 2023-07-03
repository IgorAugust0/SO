#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
  
  if (fork() == 0) {
    printf("c1\n");
  } 
  else {
  
    if (fork() == 0) 
      printf("c2\n");
  
   else
      printf("p\n");
  }
 
  return 1;
}
