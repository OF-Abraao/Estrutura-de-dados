#pragma once
#include <iostream>
using namespace std;

struct Item {
    int chave;
};

class BolhaSort {
public:
    void ordenar(Item *v, int n);

private:
    void troca(Item &a, Item &b);
};
