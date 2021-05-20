#include "defines.h"

struct sembuf UP = { 
    .sem_num = 0, 
    .sem_op = +1,
    .sem_flg = 0
};

int main() {
    int id = semget( IPC_KEY, 1, 0 );
    exit_on_error(id, "semget");
    
    int res = semop(id, &UP, 1);
    exit_on_error(res, "erro no UP");
}