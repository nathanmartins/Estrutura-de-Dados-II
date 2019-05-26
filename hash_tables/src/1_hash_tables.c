#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

int main(int argc, char const *argv[])
{

	
	int arr[10];


	for (int i = 0; i < 10; ++i)
	{
		arr[i] = i;
	}
	printIntArr(arr, 10);


	return 0;
}