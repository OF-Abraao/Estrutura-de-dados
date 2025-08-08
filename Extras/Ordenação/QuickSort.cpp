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

//QuickSort
void quick_sort(int vetor[Tam], int inicio, int fim){
    int limEsq, limDir, pivo, meio, aux;

    //Limites da esquerda e direita da região analisada
    limEsq = inicio;
    limDir = fim; 

    //Ajustando auxiliares do centro
    meio = (int) (limEsq + limDir)/2;
    pivo = vetor[meio];

    while(limDir > limEsq){
        while(vetor[limEsq]<pivo){
            limEsq = limEsq + 1; 
        }

        while(vetor[limDir]>pivo){
            limDir = limDir -1;
        }

        if(limEsq<=limDir){

            //Realiza uma troca
            aux = vetor[limEsq];
            vetor[limEsq] = vetor[limDir];
            vetor[limDir] = aux;

            //Faz os limites laterais caminharem para o centro
            limEsq = limEsq + 1; 
            limDir = limDir -1;
        }
    }
    //Recursão para continuar ordenando
    if(inicio < limDir){
        quick_sort(vetor,inicio,limDir);
    }
    if(limEsq < fim){
        quick_sort(vetor, limEsq, fim);
    }
}


