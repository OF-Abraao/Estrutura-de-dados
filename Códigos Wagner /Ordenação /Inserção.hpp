#pragma once 
#include <string>

struct Item {
    int chave;          
    std::string info;
};

using Indice = int;

void Insercao(Item *v, Indice n);

