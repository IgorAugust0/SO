#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  /* variável do tipo pid_t para identificação de processo é usado para representar o id  de um processo */
  pid_t pid;

	/* fork foi empregado para criar um processo filho */
	pid = fork();

	if (pid < 0) { /* se ocorrer erro na criação do filho o sistema finaliza */
	      fprintf(stderr, "Falha na criação de um novo processo!!!\n");
	      exit(-1);
	}
	else if (pid == 0) { /* Processo filho */
	      printf("Eu sou o processo filho com ID: %d\n",pid);
                printf("\n");
                /* A chamada de sistema execlp system call duplica a ação do shell em buscar de um arquivo executável */
	      execlp("/bin/ls","ls",NULL);         
	}
	else { /* Processo Pai */
	     /* Pai esperará o processo filho completar a tarefa */
	     printf("Eu sou o processo pai com ID: %d\n",pid);
               /* bloqueia o processo até que um de seus processos filho finalize o receba um sinal */
	     wait(NULL);
	     printf("\nProcesso filho completo\n");
	     exit(0);
	}
}
