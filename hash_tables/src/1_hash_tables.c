#include <stdlib.h>
#include <stdio.h>
#include "functions.h"


int DEBUG = 0;

int baseArr[8] = {36, 53, 70, 87, 54, 37, 71, 40};

int openAddArr[17];
int linkingArr[5];

int h1(int k, int arrSize) {
    return k % arrSize;
}

int h2(int k) {
    return 5 - (k % 5);
}

int step(int k, int arraySize) {
    return k % arraySize + 1;
}

void nullifyArrays() {

    // Nullifying addresses
    for (int i = 0; i < 17; ++i) {
        openAddArr[i] = 0;
    }

    for (int i = 0; i < 5; ++i) {
        linkingArr[i] = 0;
    }
}

int hasCollision(int location, int arr[]) {

    if (arr[location] == 0) {
        return 0;
    } else {
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

    if (DEBUG) {
        printf("Apply step returned loc(%d)\n", loc);
    }

    return loc;

}

int openAddressHash(int k) {


    int loc = h2(h1(k, 17));

    if (hasCollision(loc, openAddArr)) {
        if (DEBUG) {
            printf("Found existing item for k(%d) at openAddArr[%d]\n\n", k, loc);
        }

        loc = applyStep(loc, openAddArr, 17);
    }


    return loc;
}

void applyOpenAddressHash() {

    for (int i = 0; i < 8; ++i) {
        int loc = openAddressHash(baseArr[i]);
        openAddArr[loc] = baseArr[i];
        if (DEBUG) {
            printf("openAddArr[%d] = %d;\n", loc, baseArr[i]);
        }

    }

    printf("Processed Open Address: ");
    printIntArr(openAddArr, 17);


}

void applyLinkingHash(){


    printf("Processed Linked: ");
    printIntArr(linkingArr, 5);
}


int main(int argc, char const *argv[]) {


    nullifyArrays();

    printf("\n\n=======================================================================\n");
    printf("Open Address:           ");
    printIntArr(openAddArr, 17);
    applyOpenAddressHash();
    printf("======================================================================= \n\n\n");


    printf("=======================================================================\n");
    printf("Linked: ");
    printIntArr(linkingArr, 5);
    applyLinkingHash();
    printf("=======================================================================\n\n\n");


    printf("\n\nChange DEBUG=1 to view more complete readout...\n\n");

    return 0;
}