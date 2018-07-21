/*
 ============================================================================
 Name        : MergeSort.c
 Author      : Roberto S. Ramos Jr
 Version     :
 Copyright   : robertosrjr@gmail.com
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int vec[] = {12, 58, 16, 38, 31, 23, 37, 11, 42, 27, 47, 31};
int tamanho = 12;
int qtd = 0;

int main(void) {
	puts("Algoritmos e Estrutura de Dados em C - MergeSort"); /* prints Algoritmos e Estrutura de Dados em C - MergeSort */

	int qtde = 0;
		printf("Imprimir vector: ");
		print_vector();
		printf("\n");

		qtde = mergeSort(vec, tamanho, qtd);
		printf("Imprimir vector ordenado: ");
		print_vector();
		printf("\n");

		printf("Quantidade de Iterações: %d", qtde);

	return EXIT_SUCCESS;
}

int mergeSort(int vec[], int tam, int qtd) {
	int meio;
	if (tam > 1) {
		meio = tam / 2;
		qtd = mergeSort(vec, meio, qtd);
		qtd = mergeSort(vec + meio, tam - meio, qtd);
		junta(vec, tam);
	}
	return (qtd+1);
}

void junta(int vec[], int tam) {

	int i, j, k;
	int meio;
	int* tmp;
	tmp = (int*) malloc(tam * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}
	meio = tam / 2;
	i = 0;
	j = meio;
	k = 0;

	while (i < meio && j < tam) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		} else {
			tmp[k] = vec[j];
			++j;
		}
			++k;
	}
	if (i == meio) {
		while (j < tam) {
			tmp[k] = vec[j];
			++j;
			++k;
		}
	} else {
		while (i < meio) {
			tmp[k] = vec[i];
			++i;
			++k;
		}
	}
	for (i = 0; i < tam; ++i) {
		vec[i] = tmp[i];
	}
	free(tmp);
}

void print_vector() {

	int i;
	for (i = 0; i < tamanho -1; i++) {

		printf("%d, ", vec[i]);
	}
}
