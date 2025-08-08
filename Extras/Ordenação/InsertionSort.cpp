#include <iostream>
#define Tam 10

using namespace std;

//Função para imprimir vetor
void imprimeVetor(int vetor[]) {
	int i;
	cout << "\n";
	for(i=0; i<Tam; i++) {
		cout << " |" << vetor[i] << "| ";
	}
}


//Issertion Sort 
void insertion_sort(int vetor[]) {
    int i,j, atual;
    for(i = 1;i<Tam;i++){
        
        atual = vetor[i];
        //Elemento anterior ao analisado
        j = i - 1;
        
        while((j>=0) && (atual<vetor[j])){
            vetor[j+1] = vetor[j];
            //Faz o j andar para trás
            j = j -1;
        }
        vetor[j+1] = atual;
    }
  
}


