//
// Created by nsm
//


#include<stdio.h>

int heap[13] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4}, t, a;

void ajuste(int, int);

void sort() {
    for (int i = 13 / 2 - 1; i >= 0; i--) {
        ajuste(13, i);
    }


    for (int i = 13 - 1; i >= 0; i--) {
        t = heap[0];
        heap[0] = heap[i];
        heap[i] = t;
        ajuste(i, 0);

        printf("\nIteração #%d: ", i);

        for (a = 0; a < 13; a++) {
            printf("\t%d", heap[a]);
        }
    }
}

void ajuste(int n, int i) {
    
    int maior = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && heap[l] > heap[maior]) {
        maior = l;
    }


    if (r < n && heap[r] > heap[maior]) {
        maior = r;
    }
    
    if (maior != i) {
        t = heap[i];
        heap[i] = heap[maior];
        heap[maior] = t;
        ajuste(n, maior);
    }
}


// Imprimir o array
void printArr(int arr[], int size) {
    for (int index = 0; index < size; index++) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}


void main() {

    printf("\n\nRaw: ");
    printArr(heap, 13);

    sort();

    printf("\n\nSorted: ");
    printArr(heap, 13);
}


