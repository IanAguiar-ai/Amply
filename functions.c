#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

extern int lista[LIST_SIZE];

void remover_espacos(char *str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) 
    {
        if (str[i] != ' ') 
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; //Termina a string após a última posição válida
}

char *int_string(int numero) {
    //Calcula o tamanho necessário para a string
    int tamanho = snprintf(NULL, 0, "%d", numero);

    //Aloca memória para a string
    char *str = (char *)malloc(tamanho + 1); // +1 para o caractere nulo

    //Converte o número para a string
    snprintf(str, tamanho + 1, "%d", numero);

    return str;
}

void substituir(char *str, char character, unsigned char substituto_int)
{ //Substitui em uma lista str[] o character pelo substituto
    char *posicao = strchr(str, character);
    const char *substituto = int_string(substituto_int);
    
    while (posicao != NULL) {
        // Calcula o tamanho da string de substituição
        int tamanho_substituto = strlen(substituto);

        // Calcula o tamanho da parte restante da string original após a ocorrência do caractere alvo
        int tamanho_resto = strlen(posicao + 1);

        // Move o restante da string para frente para abrir espaço para a substituição
        memmove(posicao + tamanho_substituto, posicao + 1, tamanho_resto);

        // Copia a string de substituição para a posição onde estava o caractere alvo
        strncpy(posicao, substituto, tamanho_substituto);

        // Encontra a próxima ocorrência do caractere alvo na string
        posicao = strchr(posicao + tamanho_substituto, character);
    }
}

int encontrar_proximo_vazio() 
{ //Encontra o próximo indice com valor vazio na lista
    for (int i = 0; i < LIST_SIZE; i++) 
    {
        if (lista[i] == -1)
        {
            return i; //Retorna o índice do próximo valor vazio na lista
        }
    }
    return -1; //Retorna -1 se não houver valores vazios na lista
}

void printar_valor(int indice) 
{ //Atribui valor a lista -> print([n])
    printf("[%d] = %d\n", indice, lista[indice]);
}

void atribuir_valor(int indice, int valor) 
{ //Printa o valor pedido no indice pedido -> [n] = k
	
    lista[indice] = valor;
}

