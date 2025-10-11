#pragma once
#include <string>

struct Item {
    int chave;
    std::string info;
};

void QuickSort(Item *A, int n);
