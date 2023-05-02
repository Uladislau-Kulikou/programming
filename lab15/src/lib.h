/**
 * @file lib.h
 * @brief Contains functions for managing discipline information.
 */

#ifndef LIB_H
#define LIB_H

#include <stdio.h>

#define MAXLEN 50 ///< Maximum length of strings

/**
 * @brief Structure representing a teacher
 */
struct Teacher {
  char firstName[MAXLEN]; ///< First name of the teacher
  char lastName[MAXLEN];  ///< Last name of the teacher
  char email[MAXLEN];     ///< Email address of the teacher
};

/**
 * @brief Structure representing a discipline
 */
struct Discipline {
  int isWeekly;                 ///< Indicates if the discipline is weekly
  char name[MAXLEN];            ///< Name of the discipline
  int hours;                    ///< Number of hours the discipline takes
  struct Teacher teacher;       ///< Teacher of the discipline
  int place;                    ///< Place where the discipline takes place
};

/**
 * @brief Prints the information of a discipline
 *
 * @param[in] d Pointer to the discipline to be printed
 */
void printDiscipline(const struct Discipline *d);

/**
 * @brief Fills a discipline structure with information from a string or file
 *
 * If the `string` argument is not `NULL`, the information is read from the string.
 * Otherwise, the information is read from the file specified by the `path` argument.
 *
 * @param[out] d Pointer to the discipline to be filled
 * @param[in] path Path to the input file
 * @param[in] string String containing the input data
 */
void fillDiscipline(struct Discipline *d, char *path, char *string);

#endif /* LIB_H */
