#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Imprimir o array
void printArr(int arr[], int size){
  for(int index = 0; index < size; index++){
    printf("%d ", arr[index]);
  }
  printf("\n");
}


// trocar ponteiros de lugar
void pointerSwap(int *x, int *y){
  int t = *x; 
  *x = *y; 
  *y = t;
}


void bubble(int arr[], int n) { 
  int i, j; 
  for (i = 0; i < n-1; i++){
	  for (j = 0; j < n-i-1; j++){ 
		  if (arr[j] < arr[j+1]) {
			  pointerSwap(&arr[j], &arr[j+1]); 
      }
    }
  }	 
} 


void selection(int arr[], int n) {
  int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) { 
        min_idx = i; 
        
        // Encontrar o ultimo ordenado
        for (j = i+1; j < n; j++) {
          if (arr[j] > arr[min_idx]) {
            min_idx = j;
            // printf("Min is now %d \n", arr[j]); 
          }
        }
        
        pointerSwap(&arr[min_idx], &arr[i]); 
    } 
}



void insertion(int arr[], int n) {
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        
        key = arr[i]; 
        j = i - 1; 
        
        // Encontrar o maior e mover todos pra tras dele
        while (j >= 0 && arr[j] < key) { 

            //printf("Greatest: j => %d \n", arr[j]);
            //printf("Greatest: j+1 => %d \n", arr[j+1]);

            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        
        //printf("SWAP: j+1 = key => %d %d \n", arr[j+1], key);
        arr[j + 1] = key; 
    } 
}


int main(){
  int a[] = {4, 6, 1, 15, 85, 74,};

  // Tamanho do array, divindo numero de bits, pelo tamanho dos items.
  int sizeA = sizeof(a) / sizeof(a[0]);
  //printf("Array size: %d \n", sizeA);

  printf("\n\n===========================\n");
  printf("Unordered: ");
  printArr(a, sizeA);
  printf("===========================\n");
  
  printf("\n\n===========================\n");
  printf("Bubble Sort(Reversed): \n");
  int bubbleArr[sizeA];
  memcpy(bubbleArr, a, sizeA*sizeof(int));
  printf("Original: ");
  printArr(bubbleArr, sizeA);
  bubble(bubbleArr, sizeA);
  printf("Sorted:   ");
  printArr(bubbleArr, sizeA);
  printf("===========================\n");

  printf("\n\n===========================\n");
  printf("Selection Sort(Reversed): \n");
  int selectArr[sizeA];
  memcpy(selectArr, a, sizeA*sizeof(int));
  printf("Original: ");
  printArr(selectArr, sizeA);
  selection(selectArr, sizeA);
  printf("Sorted:   ");
  printArr(selectArr, sizeA);
  printf("===========================\n");


  printf("\n\n===========================\n");
  printf("Insertion Sort(Reversed): \n");
  int insertArr[sizeA];
  memcpy(insertArr, a, sizeA*sizeof(int));
  printf("Original: ");
  printArr(insertArr, sizeA);
  insertion(insertArr, sizeA);
  printf("Sorted:   ");
  printArr(insertArr, sizeA);
  printf("===========================\n\n\n");

  return 0;
}
