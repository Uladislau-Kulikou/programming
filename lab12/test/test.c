#include <check.h>
#include <stdlib.h>

#include "lib.h"
#define WIDTH 2
#define HEIGHT 3

START_TEST(test_transpose_matrix) {
  int **result;
  int expected_result[WIDTH][HEIGHT] = {{1, 3, 5}, {2, 4, 6}};
  int **matrix = (int **)malloc((size_t)HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    matrix[i] = (int *)malloc((size_t)WIDTH * sizeof(int));
    for (int j = 0; j < WIDTH; j++) matrix[i][j] = i * WIDTH + j + 1;
  }
  result = transpose_matrix(WIDTH, HEIGHT, matrix);

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      ck_assert_int_eq(result[i][j], expected_result[i][j]);
    }
  }

  free_matrix(WIDTH, result);
  free_matrix(HEIGHT, matrix);
}
END_TEST

int main(void) {
  int number_failed;
  SRunner *sr;

  Suite *s = suite_create("transpose_matrix");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_transpose_matrix);
  suite_add_tcase(s, tc_core);

  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
