#include <stdio.h>
int main() {
    int a, b;
    printf("Diga dois numeros: ");

    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("%d + %d = %d\n", a, b, a + b );

    // 3a) Escrever o maior
    printf("O maior número é %d\n", (a>b)? a:b);

    // 3b) Escrever por ordem
    if (a>b) {
        printf("%d, %d\n", b, a);
    } else {
        printf("%d, %d\n", a, b);
    }
}