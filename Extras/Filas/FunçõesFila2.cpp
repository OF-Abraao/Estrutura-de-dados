#include <string>
#include <iostream> 
#define TAM 10 //Tamanho da fila
using namespace std; 

//Imprimi vetor
void imprime_vetor(int vetor[TAM], int tamanho){
    //Auxiliar contador
    int cont;
    cout << "\n";
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }
    cout << "\n";
} 

//Verifica se a fila está vazia
bool fila_vazia(int frente,int atras){
    if(frente > atras){
        return true;
    }
    else{
        return false; 
    }
}

//Desenfileirar
void fila_desenfileirar(int fila[TAM], int *frente, int atras){
    if(fila_vazia(*frente, atras)){
        cout << "Impossivel desenfileirar uma lista vazia";
    }else{
        cout << "O valor " << fila[*frente] << " foi removido";
        fila[*frente] = 0;
        *frente = *frente + 1;
    }
}

