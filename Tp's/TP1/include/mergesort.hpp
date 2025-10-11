#pragma once

// Implementação do algoritmo Merge Sort genérico
template <typename T>
void merge(T array[], T buffer[], int start, int mid, int end, bool (*compare)(const T&, const T&)) {
    int i = start;
    int j = mid + 1;
    int k = start;
    
    // Combina os subarrays ordenados
    while (i <= mid && j <= end) {
        if (compare(array[i], array[j])) {
            buffer[k++] = array[i++];
        } else {
            buffer[k++] = array[j++];
        }
    }
    
    // Copia elementos restantes
    while (i <= mid) buffer[k++] = array[i++];
    while (j <= end) buffer[k++] = array[j++];
    
    // Transfere do buffer para o array original
    for (int p = start; p <= end; p++) {
        array[p] = buffer[p];
    }
}

// Função recursiva do Merge Sort
template <typename T>
void mergesort_recursive(T array[], T buffer[], int start, int end, bool (*compare)(const T&, const T&)) {
    if (start >= end) return;
    
    int mid = start + (end - start) / 2;
    mergesort_recursive(array, buffer, start, mid, compare);
    mergesort_recursive(array, buffer, mid + 1, end, compare);
    merge(array, buffer, start, mid, end, compare);
}

// Interface principal do Merge Sort
template <typename T>
void mergesort(T array[], int size, bool (*compare)(const T&, const T&)) {
    if (size <= 1) return;
    
    T buffer[size];  // Buffer temporário para mesclagem
    mergesort_recursive(array, buffer, 0, size - 1, compare);
}