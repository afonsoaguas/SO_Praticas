#include "defines.h"

/* Versão 1

int main() {
    int id = shmget( IPC_KEY, NALUNOS * sizeof(Aluno), IPC_CREAT | 0666 );
    exit_on_error(id, "shmget");

    Aluno* a = (Aluno *) shmat(id, NULL, 0);
    exit_on_null(a, "shmat");

    for( int i=0; i < NALUNOS; i++) {
        a[i].num = -1;
        strncpy(a[i].nome, "[sem nada]", 100);
        a[i].nota = 0.0;
    }
}

*/

//Versão 2

int main() {
    // Cria um semáforo para sincronização
    int sem_id = semget( IPC_KEY, 1, IPC_CREAT | 0666 );
    exit_on_error(sem_id, "semget");
		
  	// Inicializa o semáforo a 0 para impedir que outro processo possa
    // aceder à zona de memória partilhada antes da inicialização terminar
    int status = semctl(sem_id, 0, SETVAL, 0);
    exit_on_error(status, "semctl(SETVAL)");
  
    // Cria a zona de memória partilhada
    int mem_id = shmget( IPC_KEY, NALUNOS * sizeof(Aluno) , IPC_CREAT | 0666 );
    exit_on_error(mem_id, "shmget");

    // Obtém o apontador para a zona de memória
    Aluno* a = (Aluno *) shmat(mem_id, NULL , 0);
    exit_on_null(a, "shmat");
		
    // Inicializa os valores
    for( int i=0; i < NALUNOS; i++) {
        a[i].num = -1;
        strncpy(a[i].nome, "[sem nada]", 100);
        a[i].nota = 0.0;
    }

  	// A inicialização terminou, coloca o semáforo a 1 para que outros
    // processos possam aceder à zona de memória partilhada
    status = semctl(sem_id, 0, SETVAL, 1);
    exit_on_error(status, "semctl(SETVAL)");
}