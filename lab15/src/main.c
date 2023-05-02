#include <stdio.h>

#include "lib.h"

int main(int argc, char* argv[]) {
  struct Discipline prog = {1, "Програмування", 4, "Іванов", "Іван", "ivanov@gmail.com", 1};
  fillDiscipline(&prog, argv[1], NULL);  
  printDiscipline(&prog);

  return 0;
}
