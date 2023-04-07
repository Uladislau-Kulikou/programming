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

int** create_matrix(int w, int h) {
  int** matrix = (int**)malloc((size_t)h * sizeof(int*));
  for (int i = 0; i < h; i++) {
    matrix[i] = (int*)malloc((size_t)w * sizeof(int));
  }
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      printf("  (%d, %d) -> ", y + 1, x + 1);
      scanf("%d", &matrix[y][x]);
    }
  }
  return matrix;
}

int** transpose_matrix(int w, int h, int** matrix) {
  int** result = (int**)malloc((size_t)w * sizeof(int*));
  for (int i = 0; i < w; i++) {
    result[i] = (int*)malloc((size_t)h * sizeof(int));
  }
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      result[x][y] = matrix[y][x];
    }
  }
  return result;
}

void print_matrix(int w, int h, int** matrix) {
  printf("\n");
  for (int y = 0; y < h; y++) {
    printf("[");
    for (int x = 0; x < w; x++) {
      printf(" %d ", matrix[y][x]);
    }
    printf("]\n");
  }
}

void free_matrix(int size, int** matrix) {
  for (int i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);
}
