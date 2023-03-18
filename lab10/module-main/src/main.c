#include "../module-library/src/det.c"
#include <check.h>
#define N 3

int main(){
    /// Вхідні дані
    int matrix[N][N] = {{1, 2, 9},
                        {4, 5, 6},
                        {7, 8, 9}}; 

    /// Результат виконання
    int result = determinant(N, matrix); 
    return 0;
}