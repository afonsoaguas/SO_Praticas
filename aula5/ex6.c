#include <stdio.h>
#include <string.h>

int main () {
    char nome[101];
    char ultimo[101];

    printf("Primeiro nome: ");
    scanf("%100s", &nome[0]);

    printf("Último nome  : ");
    scanf("%100s", ultimo);

    // a)
    strncat(nome, " - ", 100);
    strncat(nome, ultimo, 100);
    printf("%s\n", &nome[0]);

    //b)
    if (strncmp( nome, "ISCTE - IUL", 100) == 0)
    printf("Nice :)\n");
    
    //c)
    

}