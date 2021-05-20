#include "servidor.h"

int main() {
    int id = msgget( IPC_KEY, 0 );
    exit_on_error(id, "O cliente não se conseguiu ligar ao servidor.");

    mensagem m;
    m.tipo = MSG_TYP;
    m.conteudo.pid = getpid();

    printf("Cliente : ");
    fgets( m.conteudo.nome, 20, stdin);
    m.conteudo.nome[ strlen(m.conteudo.nome) - 1 ] = 0;

    printf("Mensagem: ");
    fgets( m.conteudo.texto, 80, stdin);
    m.conteudo.texto[ strlen(m.conteudo.texto) - 1 ] = 0;

    int status;
    status = msgsnd(id, &m, sizeof(m.conteudo), 0);
    exit_on_error(status, "erro ao enviar");

    printf("A mensagem foi enviada\n");
    
    printf("...\n");
    status = msgrcv(id, &m, sizeof(m.conteudo), m.conteudo.pid, 0);
    exit_on_error(status, "erro ao receber");
    printf("A resposta foi: %s\n", m.conteudo.texto);

    return(0);
}