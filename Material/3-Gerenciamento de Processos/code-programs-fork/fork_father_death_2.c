/* Testa as reacoes do INTERPRETADOR DE COMANDO quando um pai morre e o filho continua vivo */
// Teste após a execução com o " ps -p <ID do filho> -o pid,ppid,fgroup,ni,lstart,etime"

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
int pid ;
   printf("Eu sou o pai %d e eu vou criar um filho \n",getpid()) ;
   pid=fork() ; /* criacao do filho */
   if(pid==-1) /* erro */
   {
      perror("impossivel de criar um filho\n") ;
   }    
   else if(pid==0) /* acoes do filho */
   {
      printf("\tOi, eu sou o processo %d, o filho\n",getpid()) ;
      printf("\tO dia esta otimo hoje, nao acha?\n") ;
      printf("\tBom, desse jeito vou acabar me instalando para sempre\n");
      printf("\tOu melhor, assim espero!\n") ;
      for(;;) ; /* o filho se bloqueia num loop infinito */
   }
   else /* acoes do pai */
   {
      sleep(1)  ; /* para separar bem as saidas do pai e do filho */
       printf("As luzes comecaram a se apagar para mim, %d\n",getpid()) ;
       printf("Minha hora chegou : adeus, %d, meu filho\n",pid) ;
       /* e o pai morre de causas naturais */ 
    }
    exit(0);
}
