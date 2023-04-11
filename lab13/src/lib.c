#include "lib.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_nums(char input[MAXLEN], char nums[MAXLEN]) {
  int len = 0;
  for (size_t i = 0; i < strlen(input); i++) {
    if (isdigit(input[i])) {
      nums[len] = input[i];
      nums[len + 1] = '\0';
      len++;
    }
  }
  return len;
}

void print_result(int len, char* nums) {
  printf("\n%d digits have been found.\n", len);
  for (int i = 0; i < len; i++) printf("%c ", nums[i]);
  printf("\n");
}
