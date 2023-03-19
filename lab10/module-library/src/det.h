/**
 * @file det.h
 * @brief Contains functions for calculating the determinant of a matrix.
 */

#ifndef DET_H
#define DET_H

/**
 * @brief Calculates the determinant of a square matrix.
 *
 * This function calculates the determinant of a square matrix using a recursive
 * algorithm.
 *
 * @param size The size of the matrix.
 * @param matrix A pointer to the matrix.
 * @return The determinant of the matrix.
 *
 * @code{.c}
 * // Example usage:
 * float mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
 * float det = determinant(3, mat);
 * @endcode
 */
float determinant(int size, float matrix[][size]);

#endif