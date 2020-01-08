#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @param printableArray The array that needs to be printed
 * @param arrayLength The length of the array
 */
void printArray(int printableArray[], int arrayLength);

/**
 * @param sortableArray The array which needs to be sorted
 * @param arrayLength The length of the array
 */
void bubbleSortArray(int sortableArray[], int arrayLength);

int main()
{
    int arraySize = 0;
    printf("Please, enter size for array\n");
    scanf("%d", &arraySize);

    if(arraySize <= 0) {
        printf("The entered size must be a positive number");
        return;
    }

    //Create an empty array
    int *sortArrPtr = (int*) malloc(arraySize * sizeof(int));
    if(sortArrPtr == NULL)
    {
        printf("Couldn't allocate memory");
        exit(0);
    }

    //Fill array with elements from 0 to 100
    for(int i = 0; i < arraySize; i++) {
        sortArrPtr[i] = (rand() % 100) + 1;
    }

    printf("Before sort:\n");
    printArray(sortArrPtr, arraySize);


    bubbleSortArray(sortArrPtr, arraySize);

    printf("After sort:\n");
    printArray(sortArrPtr, arraySize);

    free(sortArrPtr);
    return 0;
}


/**
 * @param printableArray The array that needs to be printed
 * @param arrayLength The length of the array
 */
void bubbleSortArray(int sortableArray[], int arrayLength)
{
    int temp = 0;

    for(int i = 0; i < arrayLength; i++) {
        for(int j = 0; j < arrayLength - 1; j++) {
            if(sortableArray[j] > sortableArray[j+1]) {
                temp = sortableArray[j+1];
                sortableArray[j + 1] = sortableArray[j];
                sortableArray[j] = temp;
            }
        }
    }
}

/**
 * @param sortableArray The array which needs to be sorted
 * @param arrayLength The length of the array
 */
void printArray(int printableArray[], int arrayLength)
{
    for(int i = 0; i < arrayLength; i++) {
        printf("Element [%d] = %d\n", i + 1, printableArray[i]);
    }
}
