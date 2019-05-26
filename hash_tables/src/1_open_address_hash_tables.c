#include <stdlib.h>
#include <stdio.h>
#include "functions.h"


int DEBUG = 0;

int SIZE = 17;

int baseArr[8] = {36, 53, 70, 87, 54, 37, 71, 40};


int h1(int k, int arrSize) {
    return k % arrSize;
}

int h2(int k) {
    return 5 - (k % 5);
}

int step(int k, int arraySize) {
    return k % arraySize + 1;
}

int hasCollision(int location, int arr[]) {

    if (arr[location] == 0) {
        return 0;
    } else {

        if (DEBUG) {
            printf("Collision at arr[%d].\n\n", location);
        }

        return 1;
    }

}

int applyStep(int loc, int arr[], int size) {

    if (DEBUG) {
        printf("Apply step called holds arr[%d] = %d\n", loc, arr[loc]);
    }


    loc = step(loc, size);

    if (hasCollision(loc, arr)) {
        loc = applyStep(loc, arr, size);
    }

//    if (DEBUG) {
//        printf("Apply step returned loc(%d)\n", loc);
//    }

    return loc;

}

int openAddressGetPosition(int k, int arr[]) {


    int loc = h2(h1(k, 17));

    if (DEBUG) {
        printf("Double hash for k(%d) is %d\n\n", k, loc);
    }


    if (hasCollision(loc, arr)) {
        if (DEBUG) {
            printf("Found existing item for k(%d) at openAddArr[%d]\n\n", k, loc);
        }

        loc = applyStep(loc, arr, SIZE);
    }


    return loc;
}

void openAddressHashInsertAll(int arr[]) {

    for (int i = 0; i < 8; ++i) {
        int loc = openAddressGetPosition(baseArr[i], arr);
        arr[loc] = baseArr[i];
        if (DEBUG) {
            printf("openAddArr[%d] = %d;\n\n\n", loc, baseArr[i]);
        }

    }

    printf("Processed Open Address: ");
    printIntArr(arr, SIZE);


}

int main(int argc, char const *argv[]) {

    int openAddArr[SIZE];

    nullifyIntArr(openAddArr, SIZE);

    printf("\n\n=======================================================================\n");
    printf("Open Address:           ");
    printIntArr(openAddArr, SIZE);
    openAddressHashInsertAll(openAddArr);
    printf("======================================================================= \n\n\n");


    printf("\n\nChange DEBUG=1 to view more complete readout...\n\n");

    return 0;
}