#include "../test_main.h"

/*START_TEST(strerror_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST*/
START_TEST(strerror_1) {
  int num_1 = 0;
  ck_assert_str_eq(strerror(num_1), s21_strerror(num_1));
}
END_TEST

START_TEST(strerror_2) {
  int num_2 = 105;
  ck_assert_str_eq(strerror(num_2), s21_strerror(num_2));
}
END_TEST

START_TEST(strerror_3) {
  int num_3 = 214748364;
  ck_assert_str_eq(strerror(num_3), s21_strerror(num_3));
}
END_TEST

START_TEST(strerror_4) {
  int num_4 = -214748364;
  ck_assert_str_eq(strerror(num_4), s21_strerror(num_4));
}
END_TEST


Suite *test_strerror(void) {
  Suite *s = suite_create("\033[45m-=S21_STRERROR=-\033[0m");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);

  suite_add_tcase(s, tc);
  return s;
}
