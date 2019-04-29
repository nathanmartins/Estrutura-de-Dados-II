#include <stdio.h>
#include <stdlib.h>


void rInsertionSort(int arr[],int index, int size){
  
  int currentValue = arr[index];
  int j = index;

  while(j > 0 && arr[j-1] > currentValue){
    arr[j] = arr[j-1];
    j--;
  }

  arr[j] = currentValue;

  if(index + 1 <= size){
    rInsertionSort(arr, index+1, size);
  }

}

// Imprimir o array
void printArr(int arr[], int size){
  for(int index = 0; index < size; index++){
    printf("%d ", arr[index]);
  }
  printf("\n");
}

int main(){
  int a[] = {-2, 4, 6, 1, 15, 85, 74,};

  // Tamanho do array, divindo numero de bits, pelo tamanho dos items.
  int sizeA = sizeof(a) / sizeof(a[0]);

  printf("\n\n===========================\n");
  printf("Unordered: ");
  printArr(a, sizeA);
  printf("===========================\n");

  rInsertionSort(a, 1, sizeA);
  
  printf("\n\n===========================\n");
  printf("Ordered: ");
  printArr(a, sizeA);
  printf("===========================\n\n\n");

  return 0;
}
