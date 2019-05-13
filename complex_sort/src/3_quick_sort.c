#include <stdio.h>
#include <stdlib.h>


void trocar(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int particao (int arr[], int low, int high) {
    int pivot = arr[low];    // pivot
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;   
            trocar(&arr[i], &arr[j]); 
        } 
    } 
    trocar(&arr[i + 1], &arr[high]); 


    printf("Resultado da particao: %d \n", i+1);

    return (i + 1); } 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = particao(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


// Imprimir o array
void printArr(int arr[]) {
    for (int index = 0; index < 16; index++) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}


int main() {

    int arr[16] = {33, 22, 55, 33,44, 22, 99, 66, 55, 11, 88, 77, 33, 88, 66 ,66};
    
    printf("RAW: ");
    printArr(arr);

    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    
    printf("Sorted:"); 
    printArr(arr); 

    return 0;
}