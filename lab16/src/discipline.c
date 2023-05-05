#include "discipline.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static const char places[4][MAXLEN] = {"KHPI_VK302", "KHPI_EK204", "KHPI_EK302", "Karazin_705"};

void printDisciplines(struct Linkedlist* disciplines) {
  struct Node* current_node = disciplines->head;
  while (current_node != NULL) {
    printf(
        "\nЄ щотижневим: %s\nНазва предмету: %s\nГодин: %d\nВикладач: %s "
        "%s\nПошта викладача: %s\nМісце проведення: %s\n\n",
        ((current_node->data->isWeekly) == true ? "Так" : "Ні"),
        current_node->data->name, current_node->data->hours,
        current_node->data->teacher.lastName,
        current_node->data->teacher.firstName,
        current_node->data->teacher.email, places[current_node->data->place]);

    current_node = current_node->next;
  }
}

void fillDisciplines(struct Linkedlist* disciplines, char* path) {
  if (path == NULL) {
    path = "assets/input.txt";
  }
  FILE* input_file = fopen(path, "r");
  char line[100];
  while (fgets(line, sizeof(line), input_file) != NULL) {
    struct Discipline* new_d = (struct Discipline*)malloc(sizeof(struct Discipline));
    sscanf(line, "%s %s %d %s %s %s %d", &new_d->isWeekly, new_d->name,
           &new_d->hours, new_d->teacher.lastName, new_d->teacher.firstName,
           new_d->teacher.email, &new_d->place);
    append(disciplines, new_d);
  }
  fclose(input_file);
}

void sortDisciplines(struct Linkedlist* disciplines, const char* field){
  bool swapped = true;
  struct Discipline* temp;
  while (swapped){
    swapped = false;
    struct Node* current_node = disciplines->head;
    struct Node* next_node = current_node->next;
    while (next_node != NULL){
      int compareResult = 0;
      if (strcmp(field, "name") == 0) {
        compareResult = strcmp(current_node->data->name, next_node->data->name);
      } 
      else if (strcmp(field, "hours") == 0) {
          compareResult = (current_node->data->hours < next_node->data->hours) ? 1 : -1;
      } 
      else if (strcmp(field, "teacher") == 0) {
          compareResult = strcmp(current_node->data->teacher.lastName, next_node->data->teacher.lastName);
        if (compareResult == 0) {
          compareResult = strcmp(current_node->data->teacher.firstName, next_node->data->teacher.firstName);
        }
      }
      else if (strcmp(field, "place") == 0) {
          compareResult = (current_node->data->place > next_node->data->place) ? 1 : -1;
      }
      if (compareResult > 0){
        temp = current_node->data;
        current_node->data = next_node->data;
        next_node->data = temp;
        swapped = true;
      }
      current_node = current_node->next;
      next_node = next_node->next;
    }
  }
}

void append(struct Linkedlist* ll, struct Discipline* data) {
  if (ll->head->data == NULL) {
    ll->head->data = data;
  } else {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    struct Node* last_node = ll->head;
    while (last_node->next != NULL) {
      last_node = last_node->next;
    }
    last_node->next = new_node;
  }
}

struct Linkedlist newLinkedList() {
  struct Linkedlist ll;
  ll.head = (struct Node*)malloc(sizeof(struct Node));
  ll.head->data = NULL;
  ll.head->next = NULL;
  return ll;
}

void deleteList(struct Linkedlist* ll, bool deleteNodes) {
  struct Node* current_node = ll->head;
  while (current_node != NULL) {
    struct Node* temp = current_node;
    current_node = current_node->next;
    if (deleteNodes) free(temp->data);
    free(temp);
  }
  ll->head = NULL;
}

void removeElement(struct Linkedlist* ll, size_t index) {
  struct Node* current_node = ll->head;
  struct Node* prev_node = NULL;

  if (index == 0) {
    ll->head = current_node->next;
    free(current_node->data);
    free(current_node);
    return;
  }
  for (int i = 0; i < index && current_node != NULL; i++) {
    prev_node = current_node;
    current_node = current_node->next;
  }
  prev_node->next = current_node->next;
  free(current_node->data);
  free(current_node);
}
