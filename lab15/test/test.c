#include <check.h>

#include "lib.h"


START_TEST(test_fill_discipline) {
  struct Discipline expected;
  fillDiscipline(&expected, NULL, "0 Фізика 4 Давидов Вячеслав davidov@gmail.com 2");
  
  ck_assert_int_eq(expected.isWeekly, 0);
  ck_assert_str_eq(expected.name, "Фізика");
  ck_assert_int_eq(expected.hours, 4);
  ck_assert_str_eq(expected.teacher.lastName, "Давидов");
  ck_assert_str_eq(expected.teacher.firstName, "Вячеслав");
  ck_assert_str_eq(expected.teacher.email, "davidov@gmail.com");
  ck_assert_int_eq(expected.place, 2);
} 
END_TEST


int main(void) {
  SRunner *sr;
  int number_failed;
  Suite *s = suite_create("fill_discipline");
  TCase *tc_core = tcase_create("lab15");
  
  tcase_add_test(tc_core, test_fill_discipline);
  suite_add_tcase(s, tc_core);

  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0: 1;
}
