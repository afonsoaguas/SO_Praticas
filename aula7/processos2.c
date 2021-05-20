#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Mostrar o conteúdo da directoria /:\n");
    if (fork() == 0) {
        execl("/bin/ls", "ls", "-l", "/", NULL);
    }else{
        wait(NULL);
        printf("Fim do comando: ls -l /\n");
    }

    return 0;
}