#include <iostream>
#define Tam 10 

using namespace std;

//Função para imprimir vetor 
void imprimeVetor(int vetor[]){
    int i; 
    cout << "\n";
    for(i=0;i<Tam;i++){
        cout << " |" << vetor[i] << "| ";
    }
}


void selection_sort(int vetor[Tam]){
    int i,j,aux,menorValor; 
    for(i=0;i<Tam;i++){
        //Recebe a posição inicial para o menor valor 
        menorValor = i;
        //Analisa os elementos na frente
        for(j=i+1;j<Tam;j++){
            //Caso encontre um valor menor na frente dos analisados
            if(vetor[j]<vetor[menorValor]){
                menorValor = j;
            }
        }
        if(menorValor != i){
            aux = vetor[i];
            vetor[i] = vetor[menorValor];
            vetor[menorValor] = aux;
        }
    }
}

