#ifndef __SERVIDOR_H__
#define __SERVIDOR_H__

#include "defines.h"

typedef struct {
    char texto[80];
    char nome[20];
    int pid;    
} Dados;

typedef struct {
    long tipo;
    Dados conteudo;
} mensagem;

#endif