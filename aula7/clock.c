#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void handler (int sinal) {
    if(fork() == 0) {
        execl("/bin/date", "date", NULL);
    }else{
        wait(NULL);
        alarm(5);
    }
}

int main() {
    printf("Ctrl+C para terminar\n");
    signal (SIGALRM, handler);
    handler(0);
    while(1) pause();
    return 0;
}