#include <stdio.h>
#include <string.h>
#include "aluno.h"

#define TURMA 10

void mostra_pauta( Aluno pauta[], int size ) {   
    printf("\n                 Pauta\n");
    printf("----------------------------------------------\n");
    
    int i;
    for( i = 0; i < size; i++) {
        if ( pauta[i].num < 0 ) break;
        printf("Aluno: %d, %s, %.2f\n", pauta[i].num, pauta[i].nome, pauta[i].nota);
    }
    printf("\nNúmero total de alunos: %d\n", i);
}

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

int adiciona_aluno( Aluno a, Aluno pauta[], int size ) {
    int i;
    for( i = 0; i < size; i++)
        if ( pauta[i].num < 0 ) break;

    if ( i >= size ) {
        fprintf(stderr,"erro: Impossível acrescentar aluno, a pauta está cheia.\n");
        return -1;
    }
    pauta[i] = a;
    return 0;
}

int apaga_aluno( int num, Aluno pauta[], int size ) {

  // Procura o aluno
  for( int i = 0; i < size; i++ ) {
    if ( pauta[i].num == num ) {
      printf("\nA remover o aluno %s\n", pauta[i].nome);
      // Copia os alunos seguintes de forma a remover o aluno
      int j;
      for( j = i; j < size-1; j++) {
        if ( pauta[j+1].num > 0 ) {
          pauta[j] = pauta[j+1];
        } else {
          break;
        }
      }
      // Coloca -1 no número do aluno que ficou livre
      pauta[j].num = -1;
      
      return 0;
    }
  }

  printf("Aluno n. %d não encontrado\n", num );
  return(-1);
}

int main() {
    Aluno pauta[TURMA];
    for(int i=0; i<TURMA; i++)
          pauta[i].num = -1;

    Aluno a;
    a.num = 23500;
    strcpy(a.nome, "Manuel Francisco");
    a.nota = 19.5;
    pauta[0] = a;
    mostra_pauta(pauta, TURMA);
    a = novo_aluno();
    if ( a.num > 0 ) pauta[1] = a;
    mostra_pauta( pauta, TURMA );
    a = novo_aluno();
    if ( a.num > 0 )
        adiciona_aluno( a, pauta, TURMA );
    mostra_pauta( pauta, TURMA );
}