#include "defines.h"

int main() {
    int id = shmget( IPC_KEY, NALUNOS * sizeof(Aluno), 0 );
    exit_on_error(id, "shmget");

    Aluno* a = (Aluno *) shmat(id, NULL, 0);
    exit_on_null(a, "shmat");

    /*Versão 1

    for( int i=0; i < NALUNOS; i++) {
        printf("Pos %d: %d %s %f\n", i, a[i].num, a[i].nome, a[i].nota);
    }

    */

    //Versão 2

    if ( a[0].num < 0 ) {
        printf("A pauta está vazia.\n");
    } else {
        int i;
        for(i= 0; i < NALUNOS && a[i].num >= 0; i++) {
            printf("Pos %d: %d %s %f\n", i, a[i].num, a[i].nome, a[i].nota);
        }
        printf("Total: %d aluno%s\n", i, (i>1)?"s":"");
    }

    // Finalizar o acesso à memória partilhada
    shmdt( (void *) a );

    //
}