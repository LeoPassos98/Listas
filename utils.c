#include <stdio.h>
#include <stdlib.h>

int* geradorVetor(int tamanho){
	int* vetor = (int*) malloc(tamanho * sizeof(int));
	return vetor;
}

void exibirVetor(int* vetor, int tamanho){
	printf("\nVetor: {");
	for(int i = 0; i < tamanho; i++){
		printf("%d ", vetor[i]);
	}
	printf("}\n");
}

void preencherVetor(int* vetor, int tamanho){
	int opcao;
	printf("\npreencherVetor\n");
	printf("vetor atual: ");
	exibirVetor(vetor, tamanho);
	printf("Como deseja preencher o vetor?\n");
	printf("1 - Ordem crescente\n");
	printf("2 - Ordem decrescente\n");
	printf("3 - Ordem Aleatorio\n");
	printf("Entre com o ordem que deseja preencher o vetor: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			for(int i = 0; i < tamanho; i++){
				vetor[i] = i + 1;
			}
			exibirVetor(vetor, tamanho);
			break;
		case 2:
			for(int i = 0; i < tamanho; i++){
				vetor[i] = tamanho - i;
			}
			exibirVetor(vetor, tamanho);
			break;
		case 3:
			for(int i = 0; i < tamanho; i++){
				vetor[i] = 1 + rand() % tamanho;
			}
			exibirVetor(vetor, tamanho);
			break;
	}
}

void swapVetor(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}