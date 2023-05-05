#include "discipline.h"

int main(int argc, char* argv[]) {
  struct Linkedlist all_disciplines = newLinkedList();
  fillDisciplines(&all_disciplines, argv[1]);
  removeElement(&all_disciplines, 4);
  sortDisciplines(&all_disciplines, "hours");
  printDisciplines(&all_disciplines);
  deleteList(&all_disciplines, true);

  return 0;
}
