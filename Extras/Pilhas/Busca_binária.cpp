#include <string>
#include <iostream>
#define value 10 //Tamanho da fila
using namespace std; 


//Imprimi o vetor
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

//Busca Binária
int busca_binária(int vetor[value],int valorProcurado, int *posição){
    int lim_esquerda = 0; //limite inferior esquerdo  
    int lim_direita = value-1;  //limite superior direito 
    int meio;

    while(lim_esquerda<=lim_direita){
        meio = (lim_direita+lim_esquerda)/2;

        //Quando o limite já é o valor do meio
        if(valorProcurado == vetor[meio]){
            *posição = meio;
            return 1;
        }
        //Ajustando os limites laterais 
        else if (vetor[meio]<valorProcurado)
        {
            lim_esquerda = meio + 1;
        }
        else{
            lim_direita = meio - 1;
        }
    }
    return -1;

}

