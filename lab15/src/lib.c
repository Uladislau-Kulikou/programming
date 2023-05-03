#include "lib.h"

#include <stdio.h>

static const char places[4][MAXLEN] = {"KHPI_VK302", "KHPI_EK204", "KHPI_EK302", "Karazin_705"};

void printDiscipline(const struct Discipline *d) {
  printf(
      "\nЄ щотижневим: %s\nНазва предмету: %s\nГодин: %d\nВикладач: %s "
      "%s\nПошта викладача: %s\nМісце проведення: %s\n\n",
      ((d->isWeekly) == true ? "Так" : "Ні"), d->name, d->hours, d->teacher.lastName, d->teacher.firstName,
      d->teacher.email, places[d->place]);
}

void fillDisciplines(struct Discipline *disciplines, int numDisciplines, char *path, char *inputString) {
  if (inputString) {
    char *token;
    char *delimiter = "\n";
    int i = 0;
    
    token = strtok(inputString, delimiter);
    while (token != NULL && i < numDisciplines) {
      sscanf(token, "%s %s %d %s %s %s %d", &disciplines[i].isWeekly, disciplines[i].name, &disciplines[i].hours, disciplines[i].teacher.lastName, disciplines[i].teacher.firstName, disciplines[i].teacher.email, &disciplines[i].place);
      i++;
      token = strtok(NULL, delimiter);
    }
  } 
  else {
    FILE *input_file = fopen(path, "r");
    if (input_file == NULL) {
      printf("\033[1;35m warning\033[0m: \033[1mCould not open input file. Used default values.\033[0m\n");
      return;
    }
    
    for (int i = 0; i < numDisciplines; i++) {
      fscanf(input_file, "%s %s %d %s %s %s %d", &disciplines[i].isWeekly, disciplines[i].name, &disciplines[i].hours, disciplines[i].teacher.lastName, disciplines[i].teacher.firstName, disciplines[i].teacher.email, &disciplines[i].place);
    }
    
    fclose(input_file);
  }
}


void sortDisciplines(struct Discipline *disciplines, const char* field, int size) {
  int i, j;
  struct Discipline temp;

  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      int compareResult = 0;

      if (strcmp(field, "назва") == 0) {
        compareResult = strcmp(disciplines[j].name, disciplines[j+1].name);
      } else if (strcmp(field, "години") == 0) {
        compareResult = (disciplines[j].hours < disciplines[j+1].hours) ? 1 : -1;
      } else if (strcmp(field, "викладач") == 0) {
        compareResult = strcmp(disciplines[j].teacher.lastName, disciplines[j+1].teacher.lastName);
        if (compareResult == 0) {
          compareResult = strcmp(disciplines[j].teacher.firstName, disciplines[j+1].teacher.firstName);
        }
      } else if (strcmp(field, "місце") == 0) {
        compareResult = (disciplines[j].place > disciplines[j+1].place) ? 1 : -1;
      }

      if (compareResult > 0) {
        temp = disciplines[j];
        disciplines[j] = disciplines[j+1];
        disciplines[j+1] = temp;
      }
    }
  }
}

void write_to_file(struct Discipline *d, int size, char* path){
  FILE *output_file = fopen(path, "w");
  if (output_file == NULL){
    printf("\033[1;35m warning:\033[0m \033[1mOutput file not specified.\033[0m\n");
    return;
  }
  for (int i=0; i < size; i++){
  fprintf(output_file, "\nЄ щотижневим: %s\nНазва предмету: %s\nГодин: %d\nВикладач: %s %s\nПошта викладача: %s\nМісце проведення: %s\n\n",
      ((d[i].isWeekly) == true ? "Так" : "Ні"), d[i].name, d[i].hours, d[i].teacher.lastName, d[i].teacher.firstName,
      d[i].teacher.email, places[d[i].place]);
  }
  fclose(output_file);
}