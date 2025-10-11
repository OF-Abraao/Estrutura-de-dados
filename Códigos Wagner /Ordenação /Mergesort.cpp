#include "Mergesort.hpp"

static void merge(int array[], int temp[], int left, int mid, int right) {
    for (int i = left; i <= right; ++i) {
        temp[i] = array[i];
    }

    int i = left;     
    int j = mid + 1;   
    int k = left;     

    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {      
            array[k++] = temp[i++];
        } else {
            array[k++] = temp[j++];
        }
    }
    while (i <= mid) {
        array[k++] = temp[i++];
    }
}

static void mergeSortRec(int array[], int temp[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortRec(array, temp, left, mid);
    mergeSortRec(array, temp, mid + 1, right);
    merge(array, temp, left, mid, right);
}

void mergeSort(int array[], int n) {
    if (array == nullptr || n <= 1) return;

    int *temp = new int[n];
    mergeSortRec(array, temp, 0, n - 1);
    delete[] temp;
}
