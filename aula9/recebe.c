#include "defines.h"

typedef struct { 
    long tipo;
    char texto[80];
} mensagem;

int main() {
    int id, status;
    id = msgget( IPC_KEY, 0 );
    exit_on_error(id, "Erro no msgget.");
    printf("Estou a usar a fila de mensagens id=%d\n", id);
    
    mensagem m;

    status = msgrcv(id, &m, sizeof(m.texto), MSG_TYP, 0);
    exit_on_error(status, "erro ao receber");
    printf("A mensagem foi: %s\n", m.texto);

    return(0);
}