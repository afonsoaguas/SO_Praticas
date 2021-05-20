#include <stdio.h>
#include "aluno.h"

Aluno novo_aluno( ) {
    Aluno a;

    printf("Novo aluno\n");

    printf("Número (0 para cancelar): ");
    scanf("%d", &a.num);
  
    if (a.num >= 1) {
      printf("Nome   : ");
      scanf("\n%100[^\n]", a.nome);

      printf("Nota   : ");
      scanf("%f", &a.nota);
    } else {
      a.num = -1;
    }

    return a;
}

int grava_pauta( Aluno pauta[], int size ) {
    FILE* ft = fopen("pauta.csv","w");
    if ( ft ) {
        for( int i = 0; i < size; i++) {
            if ( pauta[i].num < 0 ) break;
            fprintf(ft, "%d,%s,%f\n", pauta[i].num, pauta[i].nome, pauta[i].nota);
        }
        fclose(ft);
        return(0);
    } else {
        fprintf(stderr,"Erro, não foi possível abrir o ficheiro 'pauta.csv' para escrita.\n");
        return(-1);
    }
}

int le_pauta( Aluno pauta[], int size ) {
    FILE* ft = fopen("pauta.csv","r");
    if ( ft ) {
        int i;
        for( i = 0; i < size; i++ ) {
            Aluno a;
            if ( fscanf( ft, "%d,%100[^,],%f", &a.num, a.nome, &a.nota ) < 0 ) break;
            pauta[i] = a;
        };

        printf("\nO ficheiro tem %d alunos.\n", i);

        // Limpar o resto da pauta
        for(;i < size; i++) pauta[i].num = -1;

        fclose(ft);
        return(0);
    } else {
        fprintf(stderr,"Erro, não foi possível abrir o ficheiro 'pauta.csv' para leitura.\n");
        return(-1);
    }
}

int main() {
    Aluno a1 = novo_aluno();

    if ( a1.num > 0 ) {
      FILE* ft = fopen( "pauta.csv", "a");
      fprintf( ft, "%d,%s,%f\n", a1.num, a1.nome, a1.nota );
      fclose(ft);
    }
}