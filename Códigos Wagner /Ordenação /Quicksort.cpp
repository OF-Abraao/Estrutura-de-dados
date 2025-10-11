#include "Quicksort.hpp"

static void Troca(Item &a, Item &b) {
    Item tmp = a;
    a = b;
    b = tmp;
}

static void Particao(int Esq, int Dir, int *i, int *j, Item *A) {
    int esquerda = Esq;
    int direita = Dir;
    Item pivot = A[(Esq + Dir) / 2]; // pivot por valor 

    while (esquerda <= direita) {
        while (A[esquerda].chave < pivot.chave) esquerda++;
        while (A[direita].chave > pivot.chave) direita--;

        if (esquerda <= direita) {
            Troca(A[esquerda], A[direita]);
            esquerda++;
            direita--;
        }
    }

    *i = esquerda;
    *j = direita;
}

static void Ordena(int Esq, int Dir, Item *A) {
    int i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j)  Ordena(Esq, j, A);
    if (i < Dir)  Ordena(i, Dir, A);
}

void QuickSort(Item *A, int n) {
    if (A == nullptr || n <= 1) return;
    Ordena(0, n - 1, A);
}
