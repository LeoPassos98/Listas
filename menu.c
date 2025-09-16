#include <stdio.h>
#include <stdlib.h>

void menu(int* vetor, int tamanho){
   	int opcao = -1;
    	while(opcao != 0){
		printf("\n-= MENU =-\n");
		printf("1 - Bubble Sort\n");
		printf("2 - Selection Sort\n");
		printf("3 - Insertion Sort\n");
		printf("Entre com qual lista deseja: ");
		scanf("%d", &opcao);
		switch(opcao){
        	case 1:
			printf("\ncase 1: Bubble Sort\n");
			bubbleSort(vetor, tamanho);
			exibirVetor(vetor, tamanho);
    			printf("\n%d = comparacoes  %d = trocas\n", vetor[tamanho], vetor[tamanho + 1]);
			break;
		case 2:
			printf("\ncase 2: Selection Sort\n");
			selectionSort(vetor, tamanho);
			exibirVetor(vetor, tamanho);
    			printf("\n%d = comparacoes  %d = trocas\n", vetor[tamanho], vetor[tamanho + 1]);
			break;
		case 3:

			printf("\ncase 3: Insertion Sort\n");
			insertionSort(vetor, tamanho);
			exibirVetor(vetor, tamanho);
    			printf("\n%d = comparacoes  %d = movimentos\n", vetor[tamanho], vetor[tamanho + 1]);
			break;
		default:
			 printf("\ndefault: Opcao invalida\n");
		}
	}
	free(vetor);
}