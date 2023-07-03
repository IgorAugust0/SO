#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// Qual o valor do da variável value no pai?
int value = 5;

int main()
{
   pid_t pid;
   pid = fork();
	
   if (pid == 0) { /*Processo Filho*/
       printf("\n filho: %d \n", (int) pid); 
       value += 15; 
       printf ("\n Filho: valor = %d\n",value); 
       return(0);

    }
   else if (pid > 0) { /* Processo Pai */
       printf("\n pai: %d \n", (int) pid); 
	
   wait(NULL);
   printf ("\n PAI: valor = %d\n",value); 
   return(0);

  }
}
