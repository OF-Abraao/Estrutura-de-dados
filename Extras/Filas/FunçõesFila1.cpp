#include <string>
#include <iostream> 
#define TAM 10 //Tamanho da fila/vetor 
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

//Para construir uma fila 
void fila_construtor(int *frente, int *atras){
    *frente = 0;
    *atras = -1; 
}

//Verifica se a fila está cheia
bool fila_cheia(int tras){
    if(tras == TAM -1){
        return true;
    }else{
        return false;
    }
}

//Colocar novos elementos na fila
void fila_enfileirar(int fila[TAM],int valor,int *atras){
    if(fila_cheia(*atras)){
        cout << "Fila cheia" << endl;
    }
    else{
        *atras = *atras + 1;
         fila[*atras] = valor; 
    }
}


//Retorna o tamanho
int fila_tamanho(int frente, int atras){
    return (frente-atras)+1;
}

