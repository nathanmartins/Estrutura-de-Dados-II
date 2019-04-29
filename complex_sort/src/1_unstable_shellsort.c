#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int value;
} stableItem;


// Imprimir o array
void printArr(int arr[], int size) {
    for (int index = 0; index < size; index++) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

// imprime o array estavel
void printStableArr(stableItem arr[], int size) {
    for (int index = 0; index < size; index++) {
        printf("%d (ID: %d)  ", arr[index].value, arr[index].id);
    }
    printf("\n");
}

// Prepopular pra testes
void prePopulate(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
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

// popular array de
void populatestableItemArr(int arr[], stableItem vA[], int size) {
    for (int index = 0; index < size; index++) {
        vA[index].id = index + 1;
        vA[index].value = arr[index];
    }
}


void shellsortStableItems(stableItem arr[], int num) {
    int i, j, k;

    stableItem tmp;

    for (i = num / 2; i > 0; i = i / 2) {
        for (j = i; j < num; j++) {

            for (k = j - i; k >= 0; k = k - i) {
                if (arr[k + i].value >= arr[k].value)
                    break;
                else {
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }

        }
    }
}


int main() {
    int arr[30];
    int i, num;
//    printf("Enter total no. of elements : ");
//    scanf("%d", &num);

//    printf("\nEnter %d numbers: ", num);
//
//    for (int k = 0; k < num; k++) {
//        scanf("%d", &arr[k]);
//    }

    num = 5;
    stableItem vA[num];

    //prePopulate(num, arr);
    prePopulateStatic(arr);

    populatestableItemArr(arr, vA, num);
    shellsortStableItems(vA, num);
    printStableArr(vA, num);


    return 0;
}



