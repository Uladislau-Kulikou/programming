#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <stdbool.h>
#include <stddef.h>

#define MAXLEN 50

/**
 * @brief The Teacher struct represents a teacher.
 */
struct Teacher {
  char lastName[MAXLEN];   ///< Last name of a teacher
  char firstName[MAXLEN];  ///< First name of a teacher
  char email[MAXLEN];      ///< Email address of a teacher
};

/**
 * @brief The Discipline struct represents a discipline.
 */
struct Discipline {
  bool isWeekly;           ///< Indicates if a discipline is weekly
  char name[MAXLEN];       ///< Name of a discipline
  int hours;               ///< Number of hours a discipline takes
  struct Teacher teacher;  ///< Teacher of a discipline
  int place;               ///< Place where a discipline takes place
};

/**
 * @brief The Node struct represents a node in a linked list.
 */
struct Node {
  struct Discipline* data; ///< Pointer to the data stored in the node
  struct Node* next;       ///< Pointer to the next node in the linked list
};

/**
 * @brief The Linkedlist struct represents a linked list of disciplines.
 */
struct Linkedlist {
  struct Node* head; ///< Pointer to the head node of the linked list
};

/**
 * @brief Prints the list of disciplines to the console.
 * 
 * @param disciplines A pointer to the linked list of disciplines
 */
extern void printDisciplines(struct Linkedlist* disciplines);

/**
 * @brief Fills a linked list of disciplines with data read from a file.
 * 
 * @param disciplines A pointer to the linked list of disciplines
 * @param path The path to the file containing the data
 */
extern void fillDisciplines(struct Linkedlist* disciplines, char* path);

/**
 * @brief Sorts the list of disciplines by the given field.
 * 
 * @param disciplines A pointer to the linked list of disciplines
 * @param field The field to sort the list by
 */
extern void sortDisciplines(struct Linkedlist* disciplines, const char* field);

/**
 * @brief Appends a discipline to the end of a linked list.
 * 
 * @param ll A pointer to the linked list
 * @param data A pointer to the discipline to be appended
 */
extern void append(struct Linkedlist* ll, struct Discipline* data);

/**
 * @brief Creates a new empty linked list of disciplines.
 * 
 * @return The newly created linked list
 */
extern struct Linkedlist newLinkedList();

/**
 * @brief Deletes a linked list of disciplines.
 * 
 * @param ll A pointer to the linked list to be deleted
 * @param deleteNodes If true, deletes the nodes in the linked list as well
 */
extern void deleteList(struct Linkedlist* ll, bool deleteNodes);

/**
 * @brief Removes the discipline at the given index from the linked list.
 * 
 * @param ll A pointer to the linked list
 * @param index The index of the discipline to be removed
 */
extern void removeElement(struct Linkedlist* ll, size_t index);

#endif  // DISCIPLINE_H
