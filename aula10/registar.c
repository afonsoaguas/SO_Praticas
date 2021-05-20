#include "defines.h"

Aluno obter_dados_aluno() { 
    Aluno x;
    char buffer[100];

    printf("Introduzir novo aluno\n");
    printf("\n");

    printf("Número (0 para cancelar): ");
    fgets(buffer, 100, stdin); x.num=atoi(buffer);
  	
  	if ( x.num <= 0 ) {
        x.num = -1;
    } else {
        printf("Nome   : ");
        fgets(x.nome, 100, stdin); x.nome[strlen(x.nome)-1]=0;

        printf("Nota   : ");
        fgets(buffer, 100, stdin); x.nota = atof(buffer);
    }

    return x;
}

void registar_aluno(Aluno *mem, Aluno x) {
    int i;

    /*Versão 1

    for( i=0; i<NALUNOS; i++){
        if ( mem[i].num == -1 ) {
            printf("A colocar posicao %d\n",i);
            mem[i] = x;
            break;
        }
    }

    */

    //Versão 2

    for(i=0;i<NALUNOS;i++){
        if ( mem[i].num == x.num) {
          	fprintf(stderr, "Já existe um aluno com o número %d\n", x.num);
          	return;
        } else if ( mem[i].num == -1 ) {
            printf("A colocar posicao %d\n",i);
            mem[i] = x;
            break;
        }
    }

    //

    if ( i >= NALUNOS ) {
        fprintf(stderr,"A pauta está cheia, impossível registar aluno.");
    }
}

/*Versão 1

int main() {
    int mem_id = shmget( IPC_KEY, NALUNOS * sizeof(Aluno), 0 );
    exit_on_error(mem_id, "shmget");
    
    Aluno* a = (Aluno *) shmat(mem_id, NULL, 0);
    exit_on_null(a, "shmat");

    Aluno x = obter_dados_aluno();
    if ( x.num > 0 ) registar_aluno(a, x);
}

*/

//Versão 2
int main() {
    int mem_id = shmget( IPC_KEY, NALUNOS * sizeof(Aluno) , 0 );
    exit_on_error(mem_id, "shmget");
    
    Aluno* a = (Aluno *)shmat(mem_id, NULL , 0);
    exit_on_null(a, "shmat");

    Aluno x = obter_dados_aluno();
  
    if ( x.num > 0 ) {

        // Obter identificador do semáforo
        int sem_id = semget(IPC_KEY, 1, 0 );
        exit_on_error(sem_id, "semget");

        // Baixar o valor do semáforo
        // (caso o semáforo esteja a zero o processo fica em espera)
        struct sembuf DOWN = { .sem_op = -1 };
        int status = semop(sem_id, &DOWN, 1);
        exit_on_error(status, "DOWN");

        // Regista o aluno
        registar_aluno(a, x);

        // Sobe o valor do semáforo
        struct sembuf UP = { .sem_op = +1 };
        status = semop(sem_id, &UP, 1);
        exit_on_error(status, "UP");
    }
}