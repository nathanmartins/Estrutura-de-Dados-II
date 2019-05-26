#include <stdio.h>
#include <stdlib.h>


// Imprimir o array
void printArr(int arr[], int size) {
    for (int index = 0; index < size; index++) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}


// 20 5 25 25 20
void prePopulateStatic(int arr[]) {

    arr[0] = 20;
    arr[1] = 5;
    arr[2] = 25;
    arr[3] = 25;
    arr[4] = 20;}



int main() {
    int arr[30];
    prePopulateStatic(arr);

    printf("RAW: ");
    printArr(arr, 5);
    mergeSort();
    printf("SORTED: ");
    printArr(arr, 5);



    return 0; }
