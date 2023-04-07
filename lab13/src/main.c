#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "lib.h"
#define MAXLEN 256

int main() {
  char input[MAXLEN];
  char nums[MAXLEN];
  int len = 0;

  print_student_info();
  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);
  printf("%s", input);

  for (unsigned long i = 0; i < strlen(input); i++) {
    if (isdigit(input[i])) {
      nums[len] = input[i];
      nums[len + 1] = '\0';
      len++;
    }
  }

  printf("%d digits have been found.\n", len);
  for (int i = 0; i < len; i++) printf("%c ", nums[i]);
  printf("\n");

  return 0;
}
