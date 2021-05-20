#include <stdio.h>
#include <string.h>
#include "aluno.h"

#define TURMA 10

/**
 * Mostra a pauta completa, incluindo o número total de alunos
 * @param pauta     Array de alunos
 * @param size      Dimensão máxima da turma
 */ 
void mostrar_pauta( Aluno pauta[], int size ) {
    
    printf("\n                 Pauta\n");
    printf("-------------------------------------\n");
    
    int i;
    for( i = 0; i < size; i++) {
        if ( pauta[i].num < 0 ) break;
        printf("%5d | %20s | %5.2f\n", pauta[i].num, pauta[i].nome, pauta[i].nota);
    }
    printf("\nNúmero total de alunos: %d\n", i);
}

/**
 * Acrescenta aluno à pauta. Se a turma já estiver cheia imprime uma
 * mensagem de erro
 * @param a         Aluno a acrescentar
 * @param pauta     Array de alunos
 * @param size      Dimensão máxima da turma
 * @returns 0 se bem sucedido, -1 em caso de erro
 */ 
int acrescentar_aluno( Aluno a, Aluno pauta[], int size ) {
    int i;
    for( i = 0; i < size; i++) {
        if ( pauta[i].num < 0 ) break;
    }

    if ( i >= size ) {
        fprintf(stderr,"erro: Impossível acrescentar aluno, a pauta está cheia.\n");
        return(-1);
    }

    pauta[i] = a;

    return(0);
}

/**
 * Apaga um aluno da pauta
 * @param num       Número do aluno a remover
 * @param pauta     Array de alunos
 * @param size      Dimensão máxima da turma
 * @returns 0 se bem sucedido, -1 em caso de erro
 */ 
int apagar_aluno( int num, Aluno pauta[], int size ) {

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

/**
 * Pede informação ao utilizador e acrescenta novo aluno à pauta. A acção pode
 * ser cancelada introduzindo 0 como número de aluno.
 * @param pauta     Array de alunos
 * @param size      Dimensão máxima da turma
 * @returns         Variável do tipo Aluno com a informação introduzida
 */ 
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

/**
 * Grava a pauta num ficheiro de texto em formato CSV (comma separated value).
 * @param pauta     Array de alunos
 * @param size      Dimensão máxima da turma
 * @returns 0 se bem sucedido, -1 em caso de erro
 */ 
int gravar_pauta( Aluno pauta[], int size ) {
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

/**
 * Lê a pauta de um ficheiro de texto em formato CSV (comma separated value).
 * @param pauta     Array de alunos
 * @param size      Dimensão máxima da turma
 * @returns 0 se bem sucedido, -1 em caso de erro
 */ 
int ler_pauta( Aluno pauta[], int size ) {
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

/**
 * Gestão de pautas
 **/ 
int main() {

    // Inicializa a turma
    Aluno pauta[TURMA];
    for(int i=0; i<TURMA; i++) pauta[i].num = -1;

   	int num;
  	Aluno a;

    // Processa as opções do utilizador
    int opcao = -1;
    while( opcao ) {
        printf("\n");
        printf("1 - introduzir aluno\n");
        printf("2 - remover aluno\n");
        printf("3 - mostrar pauta\n");
        printf("4 - gravar pauta\n");
        printf("5 - ler pauta\n");
        printf("\n");
        printf("0 - sair\n");

        printf("\nOpção : ");
        scanf("%d",&opcao);
        fflush(stdin);

        switch (opcao) {
            case 0:
                break;
            case 1:
                a = novo_aluno( );
                if (a.num > 0)
                  	acrescentar_aluno( a, pauta, TURMA );
                break;
            case 2:
                printf("\nIntroduzir número do aluno a remover (0 para cancelar): ");
                scanf("%d", &num);
                if (num>0)
                  	apagar_aluno( num, pauta, TURMA );
                break;
            case 3:
                mostrar_pauta( pauta, TURMA );
                break;
            case 4:
                gravar_pauta( pauta, TURMA);
                break;
            case 5:
                ler_pauta(pauta, TURMA);
                break;
            default:
                printf("Opção inválida!\n");
        }
    }

    return(0);
}