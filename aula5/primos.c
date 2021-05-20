#include <stdio.h>

int primoQ( int n ) {
    for( int i = 2; i <= n/2; i++ ) {
        if ( n % i == 0 ) return 0;
    }
    return 1;
}

int main () {
    printf("Números primos entre 1 e 100:\n");
    for( int i = 2; i <= 100; i++) 
        if (primoQ(i)) printf("%3d\n",i);

}
