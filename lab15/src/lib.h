/**

    @file lib.h
    @brief This header file contains the declarations of functions and structures for managing disciplines and teachers.
    */

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 50 ///< Maximum length of strings for names and emails.

/**

    @brief Structure representing a teacher
    */
    struct Teacher {
    char firstName[MAXLEN]; ///< First name of the teacher
    char lastName[MAXLEN]; ///< Last name of the teacher
    char email[MAXLEN]; ///< Email address of the teacher
    };

/**

    @brief Structure representing a discipline
    */
    struct Discipline {
    bool isWeekly; ///< Indicates if the discipline is weekly
    char name[MAXLEN]; ///< Name of the discipline
    int hours; ///< Number of hours the discipline takes
    struct Teacher teacher; ///< Teacher of the discipline
    int place; ///< Place where the discipline takes place
    };

/**

    @brief Print a discipline's information.
    This function prints the information of a discipline, including its name, teacher's name, number of hours, and place.
    @param d Pointer to the Discipline structure to be printed.
    */
    extern void printDiscipline(const struct Discipline *d);

/**

    @brief Fill an array of disciplines with information from a file or a string.
    This function reads a file or a string containing information of disciplines and fills an array of Discipline structures with that information.
    The file or string should contain information of each discipline in the following format: "name,teacher,last name,first name,hours,place".
    @param disciplines Pointer to the array of Discipline structures to be filled.
    @param numDisciplines Number of disciplines to be read.
    @param path Path of the file to be read. If path is NULL, inputString is used instead.
    @param inputString A string containing information of disciplines in the format specified above. If path is not NULL, this parameter is ignored.
    */
    extern void fillDisciplines(struct Discipline *disciplines, int numDisciplines, char *path, char *inputString);

/**

    @brief Sort an array of disciplines by a specified field.
    This function sorts an array of Discipline structures by a specified field. The supported fields are "name", "hours", "teacher", and "place".
    @param disciplines Array of Discipline structures to be sorted.
    @param field Field by which the array is to be sorted. Valid values are "name", "hours", "teacher", and "place".
    @param size Number of elements in the array.
    */
    extern void sortDisciplines(struct Discipline disciplines[], const char* field, int size);

#endif // LIB_H