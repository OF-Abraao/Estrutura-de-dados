#include "Bolha.hpp"
#include <iostream>

using namespace std;

void BolhaSort::troca(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}
void BolhaSort::ordenar(Item *v, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < (n - i); j++) {
            if (v[j].chave < v[j - 1].chave) {
                troca(v[j - 1], v[j]);
            }
        }
    }
}