
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile int s = 0; /* Variável compartilhada */
volatile int ultimo; /* Guarda o identificador da última thread 
                        que fez acesso a esta variável */

volatile int interesse[2] = {0, 0}; /* Indica quais threads estão
                                       interessadas em entrar na região crítica */

void* f_thread_0(void *v) {
  int i;
  
  for (i = 0; i < 10; i++) {
    interesse[0] = 1; /* Marca que esta thread está interessada */
    ultimo = 0;

    while (ultimo == 0 && interesse[1]) ; 

    s = 0;
    printf("Thread 0, s = %d.\n", s); 
    
    interesse[0] = 0; /* Marca que saiu da região crítica */
  }

  return NULL;
}

void* f_thread_1(void *v) {
  int i;
  
  for (i = 0; i < 10; i++) {

    interesse[1] = 1;
    ultimo = 1;
    while (ultimo == 1 && interesse[0]) ; 

    s = 1;
    printf("Thread 1, s = %d.\n", s); 
    
    interesse[1] = 0;
  }
  return NULL; 
}

int main() {

  pthread_t thr0, thr1;

  pthread_create(&thr0, NULL, f_thread_0, NULL);
  pthread_create(&thr1, NULL, f_thread_1, NULL);

  pthread_join(thr0, NULL); 
  pthread_join(thr1, NULL); 

  return 0;
}

