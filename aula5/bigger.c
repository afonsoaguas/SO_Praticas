#include <stdio.h>

#define N 10

int max( int buffer[], int size ) {
    int max = buffer[0];
    for(int i=1; i<size; i++)
        if ( buffer[i] > max ) max = buffer[i];
    return(max);
}

int main () {
    int buffer[N];

    printf("Introduza %d números:\n", N);

    for(int i=0; i<N; i++) {
        printf("%d : ", i+1);
        scanf( "%i", &buffer[i]);
    }

    printf("\nPor ordem inversa:\n");
    for(int i=N-1; i>0; i--) {
        printf("%d, ", buffer[i]);
    }
    printf("%d\n", buffer[0]);

    // Alínea 4 - Imprimir o maior valor
    printf("Valor máximo: %d\n", max(buffer,N));
}