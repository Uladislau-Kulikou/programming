#include <stdio.h>

#include "lib.h"

#define DISCNUM 3

int main(int argc, char* argv[]) {
  struct Discipline physics = {0, "DEFAULT", 0, "DEFAULT", "DEFAULT", "DEFAULT", 0};
  struct Discipline programing = {0, "DEFAULT", 0, "DEFAULT", "DEFAULT", "DEFAULT", 0};
  struct Discipline art = {0, "DEFAULT", 0, "DEFAULT", "DEFAULT", "DEFAULT", 0};

  struct Discipline all_disciplines[DISCNUM] = {physics, programing, art};
  fillDisciplines(all_disciplines, DISCNUM, argv[1], NULL);
  sortDisciplines(all_disciplines, "години", DISCNUM);

  for (int i = 0; i < DISCNUM; i++)
      printDiscipline(&all_disciplines[i]);
  
  write_to_file(&all_disciplines, DISCNUM, argv[2]);
  return 0;
}
