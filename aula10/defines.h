#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define exit_on_error(s,m) if (s<0) {perror(m); exit(1);}
#define exit_on_null(s,m) if (s==NULL) { perror(m); exit(1); }

#define IPC_KEY 0x0a99114 // Substitua pelo seu número de aluno
#define NALUNOS 20

typedef struct {
    int num;
    char nome[100];
    float nota;
} Aluno;