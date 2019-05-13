//
// Created by nsm
//


#include<stdio.h>

int heap[5], t, a;

void ajuste(int, int);

void sort() {
    for (int i = 5 / 2 - 1; i >= 0; i--) {
        ajuste(5, i);
    }


    for (int i = 5 - 1; i >= 0; i--) {
        t = heap[0];
        heap[0] = heap[i];
        heap[i] = t;
        ajuste(i, 0);

        printf("\nIteração #%d: ", i);

        for (a = 0; a < 5; a++) {
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


// 20 5 25 25 20
void prePopulateStatic(int arr[]) {

    arr[0] = 20;
    arr[1] = 5;
    arr[2] = 25;
    arr[3] = 25;
    arr[4] = 20;

}


// Imprimir o array
void printArr(int arr[], int size) {
    for (int index = 0; index < size; index++) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}


void main() {

    prePopulateStatic(heap);
    printf("\n\nRaw: ");
    printArr(heap, 5);

    sort();

    printf("\n\nSorted: ");
    printArr(heap, 5);
}


