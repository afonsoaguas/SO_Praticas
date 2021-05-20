#include "defines.h" 

int main() {
    int id = semget(IPC_KEY, 1, IPC_CREAT | IPC_EXCL | 0666 );
    exit_on_error(id, "algo correu mal com o semget");
    
    int status = semctl(id, 0, SETVAL, 1);
    exit_on_error(status, "semctl SETVAL failed");
}