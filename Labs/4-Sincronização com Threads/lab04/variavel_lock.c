/*
 * Tentativa de proteger a região crítica.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
volatile indica ao compilador para sempre deixar os valores atualizados em memória (não fazer otimizações que deixem o valor em registradores)
*/

volatile int s = 0; /* Variável compartilhada */
int lock = 0;

void* f_thread_0(void *v) {
  
  while (lock != 0); /* Espera a "obtenção" do lock */
  lock = 1;
  
  s = 0;
  printf("Thread 0, s = %d.\n", s); 
  
  lock = 0;  /* Libera o lock */
  return NULL;
}

void* f_thread_1(void *v) {

  while (lock != 0); /* Espera a "obtenção" do lock */
  lock = 1;
  
  s = 1;
  sleep(1);
  printf("Thread 1, s = %d.\n", s); 
  
  lock = 0;  /* Libera o lock */

  return NULL;
}

int main() {

  pthread_t thr0, thr1;
  int i;

  pthread_create(&thr0, NULL, f_thread_0, NULL);
  pthread_create(&thr1, NULL, f_thread_1, NULL);

  pthread_join(thr0, NULL); 
  pthread_join(thr1, NULL);

  return 0;
}

