#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler (int sinal){
    printf("Recebi o tal sinal\n");
}

int main() {
    char s[100];

    signal(SIGUSR1, handler);

    printf("PID=%d\n", getpid());
    while(1) {
        printf("Comando: ");
        fgets(s, 100, stdin);
        s[strlen(s) -1] = '\0';
        if (strcmp(s, "sair") == 0)
            exit (0);
    }
}