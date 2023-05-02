#include "lib.h"

#include <stdio.h>

static const char places[4][MAXLEN] = {"KHPI_VK302", "KHPI_EK204", "KHPI_EK302", "Karazin_705"};

void printDiscipline(const struct Discipline *d) {
  printf(
      "\nЄ щотижневим: %d\nНазва предмету: %s\nГодин: %d\nВикладач: %s "
      "%s\nПошта викладача: %s\nМісце проведення: %s\n",
      d->isWeekly, d->name, d->hours, d->teacher.lastName, d->teacher.firstName,
      d->teacher.email, places[d->place]);
}

void fillDiscipline(struct Discipline *d, char *path, char *string) {
  if (string) {
    sscanf(string, "%d %s %d %s %s %s %d", &d->isWeekly, d->name, &d->hours, d->teacher.lastName, d->teacher.firstName, d->teacher.email, &d->place);
  } 
  else {
    FILE *input_file = fopen(path, "r");
    if (input_file == NULL) {
      printf("\033[1;35m warning\033[0m: \033[1mCould not open input file. Used default values.\033[0m\n");
      return;
    }
    fscanf(input_file, "%d %s %d %s %s %s %d", &d->isWeekly, d->name, &d->hours, d->teacher.lastName, d->teacher.firstName, d->teacher.email, &d->place);
    fclose(input_file);
  }
}
