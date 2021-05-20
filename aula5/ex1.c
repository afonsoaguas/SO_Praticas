#include <stdio.h>
int main() {
    int a=10, b=3;
    float r;
    int v[4] = {2, 6, -9, 78};
    r = (float)a / b;
    printf("A divisão de %d por %d é %f\n", a, b, r );
    
    // a) Altere o formato de impressão
    printf("A divisão de %5d por %05d é %4.2f\n", a, b, r);
    
    int x = (b > 2);
    printf("Valor de x : %d\n", x);

    // b) Mostrar a 3ª posição do array
    printf("Valor de v[2] = %d\n", v[2]);
}
