#include <stdio.h>
#include <stdlib.h>

int* geradorVetor(int tamanho);
void menu(int* vetor, int tamanho);
void bubbleSort(int* vetor, int tamanho); 
void exibirVetor(int*, int tamanho);
void preencherVetor(int* vetor, int tamanho);
void selectionSort(int* vetor, int tamanho);
void swapVetor(int* a, int* b);
void insertionSort(int* vetor, int tamanho);

int* geradorVetor(int tamanho){
	int* vetor = (int*) malloc(tamanho * sizeof(int));
	return vetor;
}

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

void bubbleSort(int* vetor, int tamanho){
	int temporario;
	int COMPARAR = 0;
	int TROCA = 0;
	printf("\nDentro do bubbleSort(); \n");
	for(int i = 0; i < tamanho - 1; i++){
		for(int j = 0; j < tamanho - 1; j++){
			COMPARAR++;
			if(vetor[j] > vetor[j + 1]){
				swapVetor(&vetor[j], &vetor[j + 1]);
				TROCA++;
			}
		}
	}
	vetor[tamanho] = COMPARAR;
	vetor[tamanho + 1] = TROCA;

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

void selectionSort(int* vetor, int tamanho){
	int temporario, posicaoDoMenor;
	int COMPARAR = 0;
	int TROCA = 0;	
	printf("\nDentro do selectionSort(); \n");
	for(int i = 0; i < tamanho - 1; i++){
		posicaoDoMenor = i;
		for(int j = i + 1; j < tamanho; j++){
			COMPARAR++;
			if(vetor[j] < vetor[posicaoDoMenor]){
				posicaoDoMenor = j;
			}
		}
		swapVetor(&vetor[i], &vetor[posicaoDoMenor]);
		TROCA++;
	}
	vetor[tamanho] = COMPARAR;
	vetor[tamanho + 1] = TROCA;
}

void swapVetor(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int* vetor, int tamanho){
	int COMPARAR = 0;
	int MOVIMENTOS = 0;
	printf("\n Dentro do insertionSort(); \n");
	for(int i = 1; i < tamanho; i++){
	int chave = vetor[i];
	int j = i - 1;
		while (j >= 0 && vetor[j] > chave){
			COMPARAR++;
			vetor[j + 1] = vetor[j];
			MOVIMENTOS++;
			j--;
		}
		vetor[j + 1] = chave;
		MOVIMENTOS++;
	}
	vetor[tamanho] = COMPARAR; 
	vetor[tamanho + 1] = MOVIMENTOS;
}



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
