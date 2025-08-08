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

//Bubble Short 
void bubble_short(int vetor[Tam]){
    int x,y,aux; 
    //Valor da esquerda sendo analisado
    for(x=0;x<Tam;x++){
        //Valor da direita sendo analisado
        for(y = x+1;y<Tam; y++){
            //Confere se precisa fazer a troca
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
    }
}

