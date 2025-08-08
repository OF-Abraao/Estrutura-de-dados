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
    cout << "\n"; 
}

//Shell Sort
void shell_sort(int vetor[Tam]){
    int i,j,atual,h=1;
    //De quantos em quantos será a analise
    while(h<Tam){
        h = 3 * h + 1;

    }    
    //Reduz a distância das analises
    while(h>1){
        h = h/3;
        for(i = h;i<Tam;i++){
        
        atual = vetor[i];
        //Elemento anterior ao analisado
        j = i - h;
        
        while((j>=0) && (atual<vetor[j])){
            vetor[j+h] = vetor[j];
            //Faz o j andar para trás
            j = j -h;
        }
        vetor[j+h] = atual;
        }
    }
}



