//
// Created by nsm
//

#include <stdio.h>


int check(int arr[], int n) {

    for (int i = 0; i <= (n - 2) / 2; i++) {

        if (arr[2 * i + 1] > arr[i]) {
            return -1;
        }
        
        if (2 * i + 2 < n && arr[2 * i + 2] > arr[i]) {
            return -1;
        }
        
    }

    return 0;
}


int main() {
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    if (check(arr, n) == 0) {
        printf("è um heap \n");
    } else {
        printf("não è um heap\n");
    }

    return 0;
} 

