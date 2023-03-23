#include <stdlib.h>
#include <stdbool.h>
#include "lib.h"

int* get_diagonal(unsigned int size, int *matrix){
    int* result = malloc(size * sizeof(int));
    for (unsigned int i=0;i<size;i++){
        result[i] = *(matrix + i * size + i);
    }
    return result;
}

void sort(unsigned int size, int array[]){
    bool swapped = true;
    // Exiting the loop if no changes were made
    for (unsigned int _ = 0; _ < size && swapped; _++){
        swapped = false;
        for (unsigned int i=0; i < size - 1; i++){
            if (array[i] > array[i+1]){
                // Swapping two variables' values, using XOR
                array[i] ^= array[i+1];
                array[i+1] ^= array[i];
                array[i] ^= array[i+1];
                swapped = true;
            }
        }
    }
}
