#include "Seleção.hpp"
#include <iostream>

using namespace std; 

void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}

void Troca(Item &a, Item &b) {
    swap(a, b);
}

void Selecao(Item *v, int n)
{
    int i, j, Min;

    for (i = 0; i < n - 1; ++i)
    {
        Min = i;
        for (j = i + 1; j < n; ++j)
        {
            if (v[j].chave < v[Min].chave)
                Min = j;
        }
        if (Min != i) // evita troca desnecessária
            Troca(v[i], v[Min]);
    }
}
