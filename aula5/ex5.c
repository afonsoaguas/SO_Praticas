#include <stdio.h>

int primoQ(int N){
    for( int i = 2; i <= n/2; i++ )
        if ( n % i == 0 ) return 0;
    return 1;
}

int contaprimos(int N){
    int nprimos=0;
    for( int i=2; i<=N; i++)
        if(primoQ(i)) nprimos++;
    return nprimos;
}

int minimo(int v[], int comp){
    int min=0;
    for(int i=0; i<comp; i++)
        if(v[i] < min ) min = v[i];
    return min;
}

int minimo2(int v[], int comp){
    int min = v[0];
    if ( comp > 1 ) {
        int tmp = minimo2( &v[1], comp-1 );
        if ( tmp < min ) min = tmp;
    }
    return min;
}

int main(){
    

}
