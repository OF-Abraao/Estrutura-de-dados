#include "Inserção.hpp"

void Insercao(Item *v, Indice n) {
    Indice i, j;
    Item aux;

    for (i = 2; i <= n; i++) {
        aux = v[i];
        j = i - 1;
        v[0] = aux; // sentinela

        while (aux.chave < v[j].chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}
