#include <string>
#include <iostream>
#define TAM 10
using namespace std; 

//Verifica se a pilha está vazia
bool pilha_vazia(int topo){
    if(topo == -1){
        return true; 
    }
    else{
        return false; 
    }
}

//Verifica se a pilha está cheia
bool pilha_cheia(int topo){
    if(topo == TAM - 1){
        return true; 
    }
    else{
        return false;
    }
}

//Tamanho da pilha
int pilha_tamanho(int topo){
    return topo + 1;
}

//Retorna o ultimo valor da pilha
int pilha_get(int pilha[TAM],int *topo){
    if(pilha_vazia(*topo)){
        cout << "A pilha está vazia" << endl;
        return 0;
    }
    else{
        return pilha[*topo];
    }
}

//Remove um valor da pilha
void pilha_pop(int pilha[TAM], int *topo){
    if(pilha_vazia(*topo)){
        cout << "A pilha já está vazia"<<endl;
    }
    else{
        cout << "\nO valor retirado é: " << pilha[*topo];
        pilha[*topo] = 0; //Apenas para ajustar na função imprimi
        *topo = *topo - 1; 
    }
} 

//Adiciona um valor na pilha
void pilha_push(int pilha[TAM],int valor, int *topo){
    //Caso não possa colocar mais valores
    if(pilha_cheia(*topo)){
        cout << "Pilha cheia" << endl; 
    }
    else{
        *topo += 1 ;
        pilha[*topo] = valor;
    }
}


//Cria uma pilha e limpa ela
void pilha_construtor(int pilha[TAM], int *topo){
    *topo = -1; 
    
    int limp; 
    for(limp = 0;limp<TAM;limp++){
        pilha[limp] = 0;
    }

}

