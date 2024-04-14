#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic.h"
#include "functions.h"
#include "memory.h"

int lista[LIST_SIZE];

void inicializar_lista() {
    for (int i = 0; i < LIST_SIZE; i++) {
        lista[i] = -1; //-1 representa um valor vazio na lista
    }
}

void compilar(char *arquivo) 
{
	//Lê o arquivo
    FILE *arq = fopen(arquivo, "r");
    if (arq == NULL) 
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

	//Aplica a lógica:
	logica(arq);
    
    fclose(arq);
}

int main() {
    inicializar_lista();

    char arquivo[50];
    printf("Arquivo que deseja compilar: ");
    scanf("%s", arquivo);

    compilar(arquivo);

    return 0;
}

