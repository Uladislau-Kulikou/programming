#include <check.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"


START_TEST(test_ncts) {
  char input[] = "t3x7 6nd s0m3 numb3r5";
  char nums[MAXLEN];
  int expected_len = 7;
  int actual_len = get_nums(input, nums);
  ck_assert_int_eq(actual_len, expected_len);
  ck_assert_str_eq(nums, "3760335");
}
END_TEST

int main(void) {
  SRunner *sr;
  int number_failed;
  Suite *s = suite_create("test_ncts");
  TCase *tc_core = tcase_create("lab13");
  
  tcase_add_test(tc_core, test_ncts);
  suite_add_tcase(s, tc_core);

  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0: 1;
}
