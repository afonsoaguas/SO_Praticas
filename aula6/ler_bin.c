#include <stdio.h>
#include "aluno.h"

int main () {
    Aluno a;
    FILE * fb = fopen ("pauta.dat", "r");
    while ( fread( &a, sizeof(a), 1, fb ) > 0 )
      printf ( "%d %s %f\n", a.num, a.nome, a.nota );
    fclose(fb);
}