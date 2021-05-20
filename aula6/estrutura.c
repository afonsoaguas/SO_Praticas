#include <stdio.h>
#include <string.h>

typedef struct {
    int num;
    char nome[101];
    float nota;
} Aluno;

int main() {
    Aluno a;
    a.num = 23500;
    strncpy(a.nome, "Afonso Águas", 100);
    a.nota = 19.5;
    printf("Aluno: %d, %s, %.2f\n", a.num, a.nome, a.nota);
}
