#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "memory.h"

extern int lista[LIST_SIZE];

void logica_em_detalhe(char linhas[4096][MAX_CHAR], int *indice_linha, char *linha)
{ //Aplica a lógica em detalhes, separar essa função permite recursão
	int endereco, indice, indice_1, indice_2, valor, indice_receptor, indice_transmissor, limite_inferior, limite_superior;
	int saltos[MAX_LINES];

	//Correções e atualizações de sintaxe:
	remover_espacos(linha); 
	int valor_vazio = encontrar_proximo_vazio();
	int valor_preenchido = valor_vazio - 1;
	substituir(linha, '#', valor_vazio);
	substituir(linha, '%', valor_preenchido);


	//Lógica:
	if(sscanf(linha, "[%d]=[%d]<[%d]", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(lista[indice_1] < lista[indice_2]){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}

	else if(sscanf(linha, "[%d]=[%d]<%d", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(lista[indice_1] < indice_2){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}

	else if(sscanf(linha, "[%d]=%d<[%d]", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(indice_1 < lista[indice_2]){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}


	else if(sscanf(linha, "[%d]=[%d]<=[%d]", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(lista[indice_1] <= lista[indice_2]){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}

	else if(sscanf(linha, "[%d]=[%d]<=%d", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(lista[indice_1] <= indice_2){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}

	else if(sscanf(linha, "[%d]=%d<=[%d]", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(indice_1 <= lista[indice_2]){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}

	else if(sscanf(linha, "[%d]=[%d]==[%d]", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(lista[indice_1] == lista[indice_2]){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}

	else if(sscanf(linha, "[%d]=%d==[%d]", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(indice_1 == lista[indice_2]){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}

	else if(sscanf(linha, "[%d]=[%d]==%d", &indice_receptor, &indice_1, &indice_2) == 3)
	{
		if(lista[indice_1] == indice_2){
			atribuir_valor(indice_receptor, 1);
		} else {
			atribuir_valor(indice_receptor, 0);
		}
	}


	//Operações:
	else if(sscanf(linha, "[%d:%d]=%d", &limite_inferior, &limite_superior, &valor) == 3) 
	{
		for(int i = limite_inferior; i <= limite_superior; i++)
		{
			atribuir_valor(i, valor);
		}
	}
	
	else if(sscanf(linha, "[%d:%d]=[%d]", &limite_inferior, &limite_superior, &valor) == 3) 
	{
		for(int i = limite_inferior; i <= limite_superior; i++)
		{
			atribuir_valor(i, lista[valor]);
		}
	}

	else if(sscanf(linha, "[%d]=%d", &indice, &valor) == 2) 
	{
		atribuir_valor(indice, valor);
	}
	
	else if(sscanf(linha, "[%d]=[%d]", &indice_receptor, &indice_transmissor) == 2)
	{
		atribuir_valor(indice_receptor, lista[indice_transmissor]);
	}
	
	else if(sscanf(linha, "[%d]=[%d - %d]", &indice, &indice_1, &indice_2) == 2) 
	{
		atribuir_valor(indice, lista[indice_1 - indice_2]);
	}
	
	else if(sscanf(linha, "[%d]=[%d + %d]", &indice, &indice_1, &indice_2) == 2) 
	{
		atribuir_valor(indice, lista[indice_1 + indice_2]);
	}

	else if(sscanf(linha, "[%d]+=%d", &indice, &valor) == 2) 
	{
		atribuir_valor(indice, lista[indice] + valor);
	}

	else if(sscanf(linha, "[%d]-=%d", &indice, &valor) == 2) 
	{
		atribuir_valor(indice, lista[indice] - valor);
	}

	else if(sscanf(linha, "[%d]*=%d", &indice, &valor) == 2) 
	{
		atribuir_valor(indice, lista[indice] * valor);
	}
	
	else if(sscanf(linha, "[%d]/=%d", &indice, &valor) == 2) 
	{
		atribuir_valor(indice, lista[indice] % valor);
	}

	else if(sscanf(linha, "[%d]+=[%d]", &indice_receptor, &indice_transmissor) == 2)
	{
		atribuir_valor(indice_receptor, lista[indice_receptor] + lista[indice_transmissor]);
	}

	else if(sscanf(linha, "[%d]-=[%d]", &indice_receptor, &indice_transmissor) == 2)
	{
		atribuir_valor(indice_receptor, lista[indice_receptor] - lista[indice_transmissor]);
	}

	else if(sscanf(linha, "[%d]*=[%d]", &indice_receptor, &indice_transmissor) == 2)
	{
		atribuir_valor(indice_receptor, lista[indice_receptor] * lista[indice_transmissor]);
	}
	
	else if(sscanf(linha, "[%d]/=[%d]", &indice_receptor, &indice_transmissor) == 2)
	{
		atribuir_valor(indice_receptor, lista[indice_receptor] % lista[indice_transmissor]);
	}


	//Saltos:
	else if(sscanf(linha, "goto:%d", &endereco) == 1)
    {
        *indice_linha = saltos[endereco];
    }
    
	else if(sscanf(linha, ":%d", &endereco) == 1)
    {
    	saltos[endereco] = *indice_linha;
    }
    
    else if(sscanf(linha, "if[%d]:%d", &indice, &endereco) == 2)
    {
    	if(lista[indice] == 1){
    		*indice_linha = saltos[endereco];
    	}
    }


	//Prints:
	else if(sscanf(linha, "print([%d:%d])", &limite_inferior, &limite_superior) == 2) 
	{
		for(int i = limite_inferior; i <= limite_superior; i++)
		{
			printar_valor(i);
		}
	}

	else if(sscanf(linha, "print([%d])", &indice) == 1) 
	{
		printar_valor(indice);
	}
}



void logica(FILE *arq)
{
    char linhas[4096][MAX_CHAR];
    int num_linhas = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), arq) != NULL && num_linhas < 4096)
    {
        strncpy(linhas[num_linhas], linha, MAX_CHAR - 1);
        linhas[num_linhas][MAX_CHAR - 1] = '\0';

        num_linhas++;
    }

    int indice_linha = 0;
    while (indice_linha < num_linhas)
    {
        logica_em_detalhe(linhas, &indice_linha, linhas[indice_linha]);
        indice_linha++;
    }
}
