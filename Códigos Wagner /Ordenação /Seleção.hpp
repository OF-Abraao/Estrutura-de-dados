#pragma once 
#include <string>

struct Item {
    int chave;         
    std::string info; 
};

void Troca(Item &a, Item &b);

void Selecao(Item *v, int n);

