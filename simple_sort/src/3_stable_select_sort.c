#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int id;
	int value;	
} stableItem;


// imprimir o array
void printArr(int arr[], int size){
  for(int index = 0; index < size; index++){
    printf("%d ", arr[index]);
  }
  printf("\n");
}

// imprime o array estavel
void printStableArr(stableItem arr[], int size){
  for(int index = 0; index < size; index++){
    printf("%d (ID: %d)  ", arr[index].value, arr[index].id);
  }
  printf("\n");
}

// trocar ponteiros de lugar
void pointerSwap(stableItem *x, stableItem *y){
  stableItem t = *x; 
  *x = *y; 
  *y = t;
}

// popular array de 
void populatestableItemArr(int arr[], stableItem vA[], int size){
  for(int index = 0; index < size; index++){
    vA[index].id = index +1;
    vA[index].value = arr[index];
  }
}

void selection(stableItem arr[], int n) {
  int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) { 
        min_idx = i; 
        
        // encontrar o ultimo ordenado
        for (j = i+1; j < n; j++) {
          if (arr[j].value == arr[min_idx].value) {
            if (arr[j].id < arr[min_idx].id) {
              min_idx = j;
            }
          } else {
          
            if (arr[j].value < arr[min_idx].value) {
              min_idx = j;
            }
          }
        }
        pointerSwap(&arr[min_idx], &arr[i]); 
    } 
}


int main(){
  int a[] = {4, 6, 6, 15, 1, 15, 85, 74,};
  
  // Tamanho do array, divindo numero de bits, pelo tamanho dos items.
  int sizeA = sizeof(a) / sizeof(a[0]);

  stableItem vA[sizeof(stableItem) * sizeA];
  populatestableItemArr(a, vA, sizeA);
  //printf("Array size: %d \n", sizeA);

  printf("\n\n===========================\n");
  printf("Unordered: ");
  printArr(a, sizeA);
  printf("Unordered struct: ");
  printStableArr(vA, sizeA);
  printf("===========================\n");

  printf("\n\n===========================\n");
  printf("Stable Selection Sort: \n");
  selection(vA, sizeA);
  printf("Sorted:   ");
  printStableArr(vA, sizeA);
  printf("===========================\n\n\n");

  return 0;
}
