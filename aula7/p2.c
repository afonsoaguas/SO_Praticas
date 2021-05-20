#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define TIME 5

int n=0;

void trata_sinal(int sinal){
    printf("Recebi sinal %d\n", sinal);
    n=1;
}

int main() {
    printf("esperar %d segundos...\n", TIME);
    signal(SIGALRM, trata_sinal);
    alarm(TIME);
    while (n==0)
        pause();
    printf("ok\n");
    return 0;
}