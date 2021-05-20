#include "servidor.h"

int main() {
    int id, status;
    id = msgget( IPC_KEY, IPC_CREAT | IPC_EXCL | 0666 );
    exit_on_error(id, "Erro no msgget.");
    printf("Estou a usar a fila de mensagens id=%d\n", id);

    mensagem m;
    while(1) {
        status = msgrcv(id, &m, sizeof(m.conteudo), MSG_TYP, 0);
        exit_on_error(status, "erro ao receber");
        printf("Recebi de %s a msg: %s\n", m.conteudo.nome, m.conteudo.texto);
        
        m.tipo = m.conteudo.pid;
        sprintf(m.conteudo.texto, "Sr(a) %s recebi a sua msg", m.conteudo.nome);
        
        status = msgsnd(id, &m, sizeof(m.conteudo), 0);
        exit_on_error(status, "erro ao enviar");
    }
}