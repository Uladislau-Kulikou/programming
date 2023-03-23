#include <check.h>
#include <stdlib.h>
#include "lib.c" 
#define SIZE 4

START_TEST(test_get_diagonal){
    int matrix[SIZE][SIZE] = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16}};
    int *result = get_diagonal(SIZE, &matrix[0][0]);
    int expected[SIZE] = {1, 6, 11, 16};
    for (unsigned int i = 0; i < SIZE; i++) {
        ck_assert_int_eq(result[i], expected[i]);
    }
    free(result);
}
END_TEST

START_TEST(test_sort){
    int array[SIZE] = {4, 2, 1, 3};
    int expected[SIZE] = {1, 2, 3, 4};
    sort(SIZE, array);
    for (unsigned int i = 0; i < SIZE; i++) {
        ck_assert_int_eq(array[i], expected[i]);
    }
}
END_TEST

static Suite *make_suite(void){
    Suite *s;
    TCase *tc_core;

    s = suite_create("lab11");
    tc_core = tcase_create("Core");

    for (int i = 0; i < 3; i++) {
        tcase_add_test(tc_core, test_get_diagonal);
        tcase_add_test(tc_core, test_sort);
    }

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void){
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = make_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
