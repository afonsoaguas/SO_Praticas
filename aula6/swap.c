#include <stdio.h>
#include <stdlib.h>

void swap (int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main( int argc, char* argv[] ) {
    
    if ( argc != 3 ) {
        fprintf(stderr,"Utilização: %s x y\n", argv[0]);
        exit(-1);
    }

    int x = atoi( argv[1] );
    int y = atoi( argv[2] );

    printf("x = %d, y = %d\n", x, y);

    printf("a trocar...\n");
    swap( &x, &y );

    printf("x = %d, y = %d\n", x, y);
}
