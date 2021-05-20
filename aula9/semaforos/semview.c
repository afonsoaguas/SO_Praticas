#include "defines.h"

int main() {
    int id = semget( IPC_KEY, 1, 0 );
    exit_on_error(id, "semget");

    int val = semctl(id, 0, GETVAL);
    printf("O valor do semáforo #0 é : %d\n", val);
}