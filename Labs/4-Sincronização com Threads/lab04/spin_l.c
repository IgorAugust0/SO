/*
 * Controle da região crítica por alternância simples.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile int s = 0; /* Variável compartilhada */
volatile int vez = 0; /* Indica de qual thread é a vez de 
                         entrar na região crítica */

void* f_thread_0(void *v) {
  int i;

  for (i = 0; i < 5; i++) {
    while (vez != 0); /* Espera ser a vez desta thread */
  
    s = 0;
    printf("Thread 0, s = %d.\n", s); 
  
    vez = 1; /* Passa a vez para a outra thread */
    sleep(1);    
  }
  return NULL;
}

void* f_thread_1(void *v) {
  int i;

  for (i = 0; i < 5; i++) {
    while (vez != 1); /* Espera ser a vez desta thread */
  
  s = 1;
  printf("Thread 1, s = %d.\n", s); 
  
  vez = 0; /* Passa a vez para a outra thread */
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

