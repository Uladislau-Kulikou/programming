#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <stdbool.h>
#include <stddef.h>

#define MAXLEN 50

struct Teacher {
  char lastName[MAXLEN];   ///< Last name of a teacher
  char firstName[MAXLEN];  ///< First name of a teacher
  char email[MAXLEN];      ///< Email address of a teacher
};

struct Discipline {
  bool isWeekly;           ///< Indicates if a discipline is weekly
  char name[MAXLEN];       ///< Name of a discipline
  int hours;               ///< Number of hours a discipline takes
  struct Teacher teacher;  ///< Teacher of a discipline
  int place;               ///< Place where a discipline takes place
};

struct Node {
  struct Discipline* data;
  struct Node* next;
};

struct Linkedlist {
  struct Node* head;
};

extern void printDisciplines(struct Linkedlist* disciplines);

extern void fillDisciplines(struct Linkedlist* disciplines, char* path);

extern void sortDisciplines(struct Linkedlist* disciplines, const char* field);

extern void append(struct Linkedlist* ll, struct Discipline* data);

extern struct Linkedlist newLinkedList();

extern void deleteList(struct Linkedlist* ll, bool deleteNodes);

extern void removeElement(struct Linkedlist* ll, size_t index);

#endif  // DISCIPLINE_H