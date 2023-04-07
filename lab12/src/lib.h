#ifndef LIB_H
#define LIB_H

/**
 * @file lib.h
 */

/**
 * @brief Prints students info, stored in assets/input.txt
 */

extern int print_student_info(void);

/**
 * @brief Creates and returns w x h matrix, filled by user input
 * @param w Matrix width
 * @param h Matrix height
 */

extern int** create_matrix(int w, int h);

/**
 * @brief Transposes a matrix
 * @param w Input matrix width
 * @param h Input matrix height
 * @param matrix Matrix to be transposed
 * @return h x w transposed matrix
 */

extern int** transpose_matrix(int w, int h, int** matrix);

/**
 * @brief Prints a matrix
 * @param w Input matrix width
 * @param h Input matrix height
 * @param matrix Matrix to be printed
 */

extern void print_matrix(int w, int h, int** matrix);

/**
 * @brief Automates 2D array memory freeing
 * @param size Input matrix length (height)
 * @param matrix Matrix to be freed
 */

extern void free_matrix(int size, int** matrix);

#endif
