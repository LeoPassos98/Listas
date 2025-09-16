#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "menu.h"


int main(){
   	int tamanho;
	printf("\nEntre com o tamanho do vetor: ");
	scanf("%d", &tamanho);
	int* vetor = geradorVetor(tamanho + 2); // O '+2' no fim do vetor armazenam COMPARAR e TROCA	
	exibirVetor(vetor, tamanho);
	preencherVetor(vetor, tamanho);
   	menu(vetor, tamanho);
    	
    	return 0;
}

