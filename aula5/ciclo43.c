#include <stdio.h>

#define N 10

int main () {
    float buffer[N];

    printf("Introduza %d números:\n", N);

    for(int i=0; i<N; i++) {
        printf("%d : ", i+1);
        scanf( "%f", &buffer[i]);
    }

    float media = buffer[0];
    for(int i=1; i < N; i++) media += buffer[i];
    media /= N;
    printf("Média : %f\n", media );

    int nmaior = 0;
    for(int i=0; i < N; i++)
        if ( buffer[i] > media ) nmaior++;
    printf("Existem %d números maiores que a média\n", nmaior );
}
