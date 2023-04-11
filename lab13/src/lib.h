#ifndef LIB_H
#define LIB_H

#define MAXLEN 256

/**
 * @file lib.h
 */

/**
 * @brief Writes numbers to nums, returns amount of occurences
 * @param input Text to be searched
 * @param nums Array to write numbers in
 * @returns total amount of numbers
 */

extern int get_nums(char input[MAXLEN], char nums[MAXLEN]);

/**
 * @brief Prints total amount of nums and what nums exactly
 * @param len total numbers amount/nums lenght
 * @param nums numbers
 */

extern void print_result(int len, char* nums);

#endif
