#include <check.h>
#include "discipline.h"

static struct Discipline ds1 = {false, "Алгебра", 10, "Бромов", "Сергей", "bromov@gmail.com", 1};
static struct Discipline ds2 = {true, "Геометрія", 2, "Сакутин", "Роман", "sakutin@gmail.com", 4};
static struct Discipline ds3 = {true, "Біологія", 5, "Есенина", "Ольга", "esenina@gmail.com", 2};


START_TEST(test_name_sort) {
  struct Linkedlist disciplines = newLinkedList();
  append(&disciplines, &ds1);
  append(&disciplines, &ds2);
  append(&disciplines, &ds3);
  sortDisciplines(&disciplines, "name");

  ck_assert_str_eq(disciplines.head->data->name, "Алгебра");
  ck_assert_str_eq(disciplines.head->next->data->name, "Біологія");
  ck_assert_str_eq(disciplines.head->next->next->data->name, "Геометрія");
  
  deleteList(&disciplines, false);  
} 
END_TEST


START_TEST(test_hours_sort) {
  struct Linkedlist disciplines = newLinkedList();
  append(&disciplines, &ds1);
  append(&disciplines, &ds2);
  append(&disciplines, &ds3);
  sortDisciplines(&disciplines, "hours");

  ck_assert_int_eq(disciplines.head->data->hours, 10);
  ck_assert_int_eq(disciplines.head->next->data->hours, 5);
  ck_assert_int_eq(disciplines.head->next->next->data->hours, 2);
  
  deleteList(&disciplines, false);  
} 
END_TEST


START_TEST(test_teacher_sort) {
  struct Linkedlist disciplines = newLinkedList();
  append(&disciplines, &ds1);
  append(&disciplines, &ds2);
  append(&disciplines, &ds3);
  sortDisciplines(&disciplines, "teacher");

  ck_assert_str_eq(disciplines.head->data->teacher.lastName, "Бромов");
  ck_assert_str_eq(disciplines.head->next->data->teacher.lastName, "Есенина");
  ck_assert_str_eq(disciplines.head->next->next->data->teacher.lastName, "Сакутин");
  
  deleteList(&disciplines, false);  
} 
END_TEST



START_TEST(test_place_sort) {
  struct Linkedlist disciplines = newLinkedList();
  append(&disciplines, &ds1);
  append(&disciplines, &ds2);
  append(&disciplines, &ds3);
  sortDisciplines(&disciplines, "teacher");

  ck_assert_int_eq(disciplines.head->data->place, 1);
  ck_assert_int_eq(disciplines.head->next->data->place, 2);
  ck_assert_int_eq(disciplines.head->next->next->data->place, 4);
  
  deleteList(&disciplines, false);  
} 
END_TEST


int main(void) {
  SRunner *sr;
  int number_failed;
  Suite *s = suite_create("Discipline sorting");
  TCase *tc_core = tcase_create("lab16");
  
  tcase_add_test(tc_core, test_name_sort);
  tcase_add_test(tc_core, test_hours_sort);
  tcase_add_test(tc_core, test_teacher_sort);
  tcase_add_test(tc_core, test_place_sort);

  suite_add_tcase(s, tc_core);

  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0: 1;
}
