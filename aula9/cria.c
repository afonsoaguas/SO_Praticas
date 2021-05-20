#include "defines.h"

int main(){

    int id = msgget(IPC_KEY, IPC_CREAT | 0600 );
    exit_on_error(id, "Erro no msgget");
    printf("Estou a usar a fila de mensagens id=%d\n", id);

    return(0);
}