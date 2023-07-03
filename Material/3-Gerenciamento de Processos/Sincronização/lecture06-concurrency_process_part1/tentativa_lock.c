#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile int s = 0; /* Variável compartilhada  - não armazenar o valor em cache para consultas (otimizada)*/
volatile int lock = 0; /* spin lock */ 

void* f_thread_0(void *v) {
  
  while (lock == 1); /* Espera a "obtenção" do lock */
  lock = 1;
  
  s = 0;
  printf("Thread 0, s = %d.\n", s); 
  
  lock = 0;  /* Libera o lock */
  return NULL;
}

void* f_thread_1(void *v) {

  while (lock == 1); /* Espera a "obtenção" do lock */
  lock = 1;
  
  s = 1;
  printf("Thread 1, s = %d.\n", s); 
  
  lock = 0;  /* Libera o lock */

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

