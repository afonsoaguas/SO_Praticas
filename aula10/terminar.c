#include "defines.h"
#include <errno.h>

int main() {

    // Apaga o semáforo
    int semid = semget(IPC_KEY, 1, 0 );
    if ( semid == -1 ) {
        fprintf(stderr,"(*erro*) Não foi possível obter o ID do semáforo: %s\n", 
                strerror(errno));
    } else {
        if ( semctl( semid, 0, IPC_RMID ) == -1 ) {
            fprintf(stderr,"(*erro*) Não foi possível apagar o semáforo: %s\n",
                    strerror(errno));
        }
    }

    // Marca a zona de memória para ser apagada
    int shmid = shmget( IPC_KEY, 0, 0 );
    if ( shmid == -1 ) {
        fprintf(stderr,"(*erro*) Não foi possível obter o ID da zona de memória partilhada: %s\n", 
                strerror(errno));
    } else {
        if ( shmctl( shmid, IPC_RMID, NULL ) == -1 ) {
            fprintf(stderr,"(*erro*) Não foi possível marcar a memória partilhada para ser apagada: %s\n", 
                    strerror(errno));
        }
    }
}