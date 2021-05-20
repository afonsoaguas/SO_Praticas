#include <stdio.h>

void linha( int n ) {
    for( int i = 0; i < n; i++) printf("*");
    printf("\n");
}

void col( int n ) {
    printf("*");
    for( int i = 1; i < n-1; i++) printf(" ");
    printf("*\n");
}

int main () {
    int altura = 4;
    int largura = 6;

    linha( largura );
    for( int j = 1; j < altura-1; j++) col( largura );
    linha( largura );
}