#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int print_student_info(void) {
  FILE* fp;
  char buffer[BUFFER_SIZE];
  size_t bytes_read;
  fp = fopen("assets/input.txt", "r");
  bytes_read = fread(buffer, 1, BUFFER_SIZE, fp);

  if (bytes_read == 0) {
    printf("Ошибка при чтении файла!\n");
    return 1;
  }
  fclose(fp);
  printf("%s", buffer);
  return 0;
}
