#include <stdio.h>
#include <stdlib.h>



void bubbleSort(int* vetor, int tamanho); 
void selectionSort(int* vetor, int tamanho);
void insertionSort(int* vetor, int tamanho);





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


