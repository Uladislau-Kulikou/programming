#ifndef DET_H
#define DET_H

/**
 * @file lib.h
 */

/**
 * @brief Returns the main diagonal of a square matrix.
 * Time comlexity: O(n) 
 *
 * @param size The size of the matrix.
 * @param matrix A pointer to the matrix.
 * @return 1D array.
 *
 * @code{.c}
 * // Example usage:
 * int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
 * int *diag = determinant(3, matrix);
 * @endcode
 */


// takes 2D array NxN and returns a 1D array, consisting of a main diagonal
extern int* get_diagonal(unsigned int size, int *matrix);

/**
 * @brief Sorts an integer array.
 * Time complexity: O(n^2) in worst case scenario
 *
 * @param size The size of the matrix.
 * @param array An integer array.
 *
 * @code{.c}
 * // Example usage:
 * int diag[3] = {9, 5, 1};
 * sort(diag);
 * @endcode
 */

// Sorts incoming 1D array using bubble sort
extern void sort(unsigned int size, int array[]);


#endif

