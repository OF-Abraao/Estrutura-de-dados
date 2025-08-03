#include <string>
#include <iostream>
#define TAM 10 //Tamanho da fila
using namespace std; 

//Imprimi o vetor
void imprime_vetor(int vetor[TAM]){
    int cont;
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont]<< " - ";
    }
}

//Remove um valor na pilha
void pilha_pop(int pilha[TAM], int *topo){
    if(*topo == -1){
        cout << "A pilha já está vazia"<<endl;
    }
    else{
        cout << "\nO valor retirado é: " << pilha[*topo];
        pilha[*topo] = 0; //Apenas para ajustar na função imprimi
        *topo = *topo - 1; 
    }
} 


