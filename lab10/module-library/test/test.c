#include <check.h>
#include "../src/det.c"
#define TESTS_NUMBER 3

START_TEST(test_determinant){
  float matrix1[3][3] = {{1.0f, 2.0f, 9.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}};
  float matrix2[3][3] = {{1.0f, 2.0f, 9.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, -9.0f}};
  float matrix3[3][3] = {{1.1f, 2.0f, -9.0f}, {4.0f, 5.5f, 6.0f}, {7.7f, 0.0f, 9.0f}};
  float (*matrixes[TESTS_NUMBER])[3][3] = {&matrix1, &matrix2, &matrix3};
  
  int matrixes_size[TESTS_NUMBER] = {3, 3, 3};
  float expected_values[TESTS_NUMBER] = {-18.0f, 36.0f, 456.0f};
  for (int i=0; i < TESTS_NUMBER; i++){
    float actual_value = determinant(matrixes_size[i],matrixes[i]);
    ck_assert_float_eq_tol(actual_value, expected_values[i], 0.0001f);
  }
}   
END_TEST


int main(void) {
  Suite *s = suite_create("determinant");
  TCase *tc_core = tcase_create("lab09");

  tcase_add_test(tc_core, test_determinant);
  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0: 1;
}
