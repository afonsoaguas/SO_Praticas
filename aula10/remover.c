#include "defines.h"

int remove_aluno( int num, Aluno* pauta ) {

  // Procura o aluno
  for( int i = 0; i < NALUNOS; i++ ) {
    if ( pauta[i].num == num ) {
      printf("\nA remover o aluno %s\n", pauta[i].nome);
      // Copia os alunos seguintes de forma a remover o aluno
      int j;
      for( j = i; j < NALUNOS-1; j++) {
        if ( pauta[j+1].num > 0 ) {
          pauta[j].num = pauta[j+1].num;
          strncpy( pauta[j].nome, pauta[j+1].nome, 100 );
          pauta[j].nota = pauta[j+1].nota;
        } else {
          break;
        }
      }
      // Coloca -1 no número do aluno que ficou livre
      pauta[j].num = -1;
      return 0;
    }
  }

  return(-1);
}

int main() {

    int num;
		printf("Introduza número do aluno a remover (0 para cancelar): ");
    scanf("%d", &num);
  
    if (num > 0) {
      int mem_id = shmget( IPC_KEY, NALUNOS * sizeof(Aluno) , 0 );
      exit_on_error(mem_id, "shmget");

      Aluno* a = (Aluno *)shmat(mem_id, NULL , 0);
      exit_on_null(a, "shmat");

      int sem_id = semget(IPC_KEY, 1, 0 );
      exit_on_error(sem_id, "semget");

      // Bloqueia acesso à memória partilhada
      // Caso a memória esteja em uso fica à espera
      struct sembuf DOWN = { .sem_op = -1 };
      int status = semop(sem_id, &DOWN, 1);
      exit_on_error(status, "DOWN");

      if ( remove_aluno(num, a) == -1 ) {
        	fprintf(stderr,"Aluno n. %d não encontrado\n", num );
      } else {
        	printf("Aluno removido.\n");
      };

      // Liberta acesso à memória partilhada
      struct sembuf UP = { .sem_op = +1 };
      status = semop(sem_id, &UP, 1);
      exit_on_error(status, "UP");
    }
}
