#include <stdio.h>
#include <string.h>

#define MAX 1024

int main (int argc, char *argv[]) {
	printf("Nº de argumentos: %d\n", argc);
	for (int i=0; i<argc; i++)
		printf("%d-> %s (len:%zu)\n", i,argv[i], strnlen(argv[i], MAX) );
}
