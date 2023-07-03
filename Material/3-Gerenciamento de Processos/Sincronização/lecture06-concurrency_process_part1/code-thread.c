#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **ptr;  /* global */

/* função thread */
void *thread(void *vargp)
{
    int myid = (int) vargp;
    static int cnt = 0;
    
    printf("[%d]: %s (shareVar=%d)\n", 
         myid, ptr[myid], ++cnt);
}

int main()
{
    int i;
    pthread_t tid;

    char *msgs[2] = {
        "Olá de m1",
        "Olá de m2"
    };
    ptr = msgs;

    for (i = 0; i < 2; i++)
        pthread_create(&tid, NULL, thread, (void*) i);
    pthread_exit(NULL);
}
