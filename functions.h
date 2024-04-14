#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remover_espacos(char *str);
char *int_string(int numero);
void substituir(char *str, char character, unsigned char substituto_int);
int encontrar_proximo_vazio();
void printar_valor(int indice);
void atribuir_valor(int indice, int valor);

#endif /* FUNCTIONS_H */
