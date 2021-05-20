#include <stdio.h>
#include "aluno.h"

int main () {
    Aluno a;
    
    // "r+" significa leitura e escrita
    FILE * fb = fopen ("pauta.dat", "r+");
    
    // Lê o 3.º aluno
    fseek( fb, 2*sizeof(Aluno), SEEK_SET );
    fread( &a, sizeof(a), 1, fb );

    // Aumenta a nota em 0.5 valores
    a.nota += 0.5;

    printf("Nova nota:\n");
    printf("%d %s %f\n", a.num, a.nome, a.nota );

    // Recua a posição do ficheiro 1 aluno
    fseek( fb, -1*sizeof(Aluno), SEEK_CUR );
    
    // Escreve a informação deste aluno
    fwrite ( &a, sizeof(a), 1, fb );

    fclose(fb);
}