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
