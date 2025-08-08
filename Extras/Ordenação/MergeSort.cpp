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

//Juta os dois subarrays criados ao dividir o vetor principal
void merge(int vetor[Tam], int esq, int meio, int dir){
    //Auxiliares
    int i, j, k; 
    //Tamanho do primeiro vetor auxiliar
    int aux1 = meio - esq + 1;
    int aux2 = dir - meio;      //Tamaho do segundo vetor auxiliar
   
    //Cria dois Arrays temporários
    int vetorEsq[aux1], vetorDir[aux2];

   //Passa os elementos do vetor principal para o primeiro vetor auxiliar (Esquerda)
   for(i = 0;i<aux1;i++){
        vetorEsq[i] = vetor[esq+i];
   }
   //Passa os elementos do vetor principal para o segundo vetor auxiliar (Direita)
   for(j=0;j<aux2;j++){
        vetorDir[j] = vetor[meio+1+j];
   }
   
   //Reseta as variáveis
   i=0;
   j=0;
   k=esq;


   while(i<aux1 && j<aux2){
        //Caso o valor na esquerda seja menor ou igual
        if(vetorEsq[i]<=vetorDir[j]){
            //Passa para o meu vetor principal o valor menor
            vetor[k] = vetorEsq[i];
            //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
            i++;
        }
        else{
            //Passa para o meu vetor principal o valor menor
            vetor[k] = vetorDir[j];
            //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
            j++;
        }
        //Aumenta o índice de posicionamento do vetor
        k++;
   }
    //Se faltarem alguns elemntos do array ESQUERDO passa eles para o array principal
    while(i < aux1){
        vetor[k] = vetorEsq[i];
        i++;
        k++;
    }
    //Se faltarem alguns elemntos do array DIREITO passa eles para o array principal
    while(j < aux2){
        vetor[k] = vetorDir[j];
        j++;
        k++;
    }
}


//Função principal
void merge_sort(int vetor[Tam],int esq, int dir){
      
    //Encontra o meio
    if(esq < dir){
        int meio = esq + (dir-esq)/2;
    

    //Da metade para trás
    merge_sort(vetor, esq , meio);
    //Da metade para frente
    merge_sort(vetor, meio+1 , dir);

    //Une os dois sub-arrays que foram criados 
    merge(vetor,esq,meio,dir);
    }
}

