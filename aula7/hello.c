#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_alarm(int signal){
    printf("Demasiado lento...\n");
    exit(1);
}

int main() {
    char nome[100];
    printf("Introduza o seu nome: ");

    signal(SIGALRM, handle_alarm);

    alarm(2);

    scanf("%99[^\n]", nome);
    printf("Olá %s\n", nome);
    return 0;
}