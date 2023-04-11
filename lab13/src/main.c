#include <stdio.h>

#include "lib.h"

int main() {
  char input[MAXLEN];
  char nums[MAXLEN];
  int len;
  fgets(input, sizeof(input), stdin);

  len = get_nums(input, nums);
  print_result(len, nums);

  return 0;
}
