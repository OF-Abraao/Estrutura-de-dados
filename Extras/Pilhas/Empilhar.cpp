#include <string>
#include <iostream>
#define TAM 10 //Tamanho da fila
using namespace std; 

//Imprimi um vetor 
void imprime_vetor(int vetor[TAM]){
    int cont;
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont]<< " - ";
    }
}

//Adiciona um valor na pilha
void pilha_push(int pilha[TAM],int valor, int *topo){
    //Caso não possa colocar mais valores
    if(*topo == TAM - 1){
        cout << "Pilha cheia" << endl; 
    }
    else{
        *topo += 1 ;
        pilha[*topo] = valor;
    }
}
