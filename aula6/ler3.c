#include <stdio.h>
#include "aluno.h"

int main () {
    Aluno a;
    FILE * fb = fopen ("pauta.dat", "r");
    
    /* 
      - Usa-se 2*sizeof(Aluno) para posicionar o ficheiro
        na posição do 3.º aluno (lembre-se que no C a 1.ª 
        posição é 0)
      - SEEK_SET significa que a posição é relativa ao
        início do ficheiro
    */

    fseek( fb, 2*sizeof(Aluno), SEEK_SET );
    
    fread( &a, sizeof(a), 1, fb );
    printf ( "%d %s %f\n", a.num, a.nome, a.nota );
    fclose(fb);
}