#include "defines.h"

typedef struct {
    long tipo;
    char texto[80];
} mensagem;

int main() {
    int id, status;
    id = msgget(IPC_KEY, 0);
    exit_on_error(id, "Erro no msgget.");
    printf("Estou a usar a fila de mensagens id=%d\n", id);

    mensagem m;
    m.tipo = MSG_TYP;
    printf("Diga a mensagem: ");
    fgets(m.texto, 80, stdin);

    status = msgsnd(id, &m, sizeof(m.texto), 0);
    exit_on_error(status, "Erro ao enviar");
    printf("A mensagem foi enviada\n");

    return(0);
}