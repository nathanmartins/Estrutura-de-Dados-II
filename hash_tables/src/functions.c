/*
	IMPLEMENTAÇÃO DA MINHA LIB PESSOAL
*/


#include <stdlib.h>
#include <stdio.h>

#include "functions.h"



void printIntArr(int arr[], int size) {
  

  for(int index = 0; index < size; index++){
    printf("%d ", arr[index]);
  }
  printf("\n");}


void nullifyIntArr(int arr[], int size){

    // Nullifying addresses

    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}


int hasCollision(int arr[], int location, int debug) {

    if (arr[location] == 0) {
        return 0;
    } else {

        if (debug) {
            printf("Collision at arr[%d]!\n\n", location);
        }

        return 1;
    }

}