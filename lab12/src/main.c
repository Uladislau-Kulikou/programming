#include "lib.c"

int main(void) {
  int width, height;
  int** matrix;
  int** result;

  print_student_info();

  printf("Enter the width and height of the matrix: ");
  scanf("%d %d", &width, &height);
  printf("Now fill the matrix.\n");

  matrix = create_matrix(width, height);
  result = transpose_matrix(width, height, matrix);

  printf("\nYou entered: \n");
  print_matrix(width, height, matrix);
  printf("\nTransposed matrix is: \n");
  print_matrix(height, width, result);

  free_matrix(height, matrix);
  free_matrix(width, result);

  return 0;
}
