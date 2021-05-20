#include <stdio.h>

#define N 10

void sort( int buffer[], int size ) {

    for( int j = size-1; j > 0; j-- ) {
        for( int i = 0; i < j; i++) {
            if ( buffer[i] > buffer [i+1] ) {
                int tmp = buffer[i];
                buffer[i] = buffer[i+1];
                buffer[i+1] = tmp;
            }
        }
    }
}

int main () {

    int buffer[N];
    printf("Introduza %d números inteiros:\n", N);

    for(int i=0; i<N; i++) {
        printf("%d : ", i+1);
        scanf( "%d", &buffer[i]);
    }

    sort( buffer, N );

    printf("Lista ordenada:\n");
    for(int i=0; i<N-1; i++) 
        printf("%d, ", buffer[i]);
    printf("%d\n", buffer[N-1]);

}