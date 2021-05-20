#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Inicio PID=%d filho de %d\n", getpid(), getppid());

    if (fork() == 0){
        printf("Eu sou filho, PID = %d\n", getpid());
    }else{
        wait( NULL );
        printf("Eu sou o pai\n");
    }
    printf("Fim PID=%d filho de %d\n", getpid(), getppid());

    return 0;
}