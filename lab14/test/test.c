#include <check.h>
#include "lib.h"

#define COLS 40
#define ROWS 11

START_TEST(test_file) {
  char expected_result[ROWS][COLS] = {
          "       *******                          ",
          "     ***     ***                        ",
          "   ***         ***                      ",
          "  **             **                     ",
          " **               **                    ",
          "**                 ***                  ",
          "                     **               **",
          "                      **             ** ",
          "                       ***         ***  ",
          "                         ***     ***    ",
          "                           *******      "};

  char** result = init_graph(COLS, ROWS);
  calculate_points(COLS, result, 40.0, 5.0, '*');

  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLS; x++) {
      ck_assert_int_eq(result[y][x], expected_result[y][x]);
    }
  }
  delete_graph(ROWS, result);
}
END_TEST

int main(void) {
  SRunner *sr;
  int number_failed;
  Suite *s = suite_create("test_file");
  TCase *tc_core = tcase_create("lab14");
  
  tcase_add_test(tc_core, test_file);
  suite_add_tcase(s, tc_core);

  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0: 1;
}
