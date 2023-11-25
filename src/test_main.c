#include <string.h>
#include <stdlib.h>
#include <check.h>

#include "s21_string.h"
#include "data_test.h"

START_TEST(s21_memcmp_test)
{
    ck_assert_int_eq(s21_memcmp(test1, test2, 6), memcmp(test1, test2, 6));
    ck_assert_int_eq(s21_memcmp(test2, test3, 5), memcmp(test2, test3, 5));
    ck_assert_int_eq(s21_memcmp(test3, test4, 5), memcmp(test3, test4, 5));
    ck_assert_int_eq(s21_memcmp(test4, test5, 4), memcmp(test4, test5, 4));
}

END_TEST

Suite *test_suite(void) {
    Suite *s;
    s = suite_create("Check");
    TCase *tc_memcmp;
    tc_memcmp = tcase_create("memcmp_test");
    tcase_add_test(tc_memcmp, s21_memcmp_test);
    suite_add_tcase(s, tc_memcmp);
    return s;

}

int main() 
{ 
    int failed = 0;
    Suite *s;
    SRunner *runner;
    s = test_suite();
    runner = sranner_create(s);
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
