#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

int main(int argc, char const *argv[]) {


    int openAddArr[17];


    for (int i = 0; i < 17; ++i) {
        openAddArr[i] = i;
    }

    printIntArr(openAddArr, 17);


    return 0;
}