#include <string>
#include <iostream>
#define value 10 //Tamanho da fila
using namespace std;
 
void imprime_vetor(int vetor[value]){
    int cont;
    for(cont = 0; cont < value; cont++){
        cout << vetor[cont];
        if(cont == 9){
            break;
        }
        else{
            cout << " - ";
        }
    }
 
}


//Busca simples
int busca_simples(int vetor[value],int valorProcurado, int *posição){
    int i;
    bool valorEncontrado; 

    for(i=0;i<value;i++){
        if(vetor[i] == valorProcurado){
            valorEncontrado = true;
            *posição = i;
        }
    }
    if(valorEncontrado){
        return 1;
    }
    else{
        return -1;
    }
}


