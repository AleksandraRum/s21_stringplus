#include "../test_main.h"

START_TEST(sprintf_1_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%c Test";
  int a = 9;
  ck_assert_int_eq(sprintf(str1, str3, a),
                   s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%05c Test";
  int a = -6;
  ck_assert_int_eq(sprintf(str1, str3, a),
                   s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hi % -10c";
  int c = 1744;
  ck_assert_int_eq(sprintf(str1, str3, c ),
                   s21_sprintf(str2, str3, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%+010.5c";
  int a = 60;
  ck_assert_int_eq(sprintf(str1, str3, a ),
                   s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%+10.5c";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a),
                   s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%6.4c  st";
  unsigned long int b = 70;
  ck_assert_int_eq(sprintf(str1, str3,  b),
                   s21_sprintf(str2, str3, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "g %21c";
  int a = 74;
  ck_assert_int_eq(sprintf(str1, str3, a),
                   s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST


START_TEST(sprintf_8_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "g %c";
  ck_assert_int_eq(sprintf(str1, str3, 'T'),
                   s21_sprintf(str2, str3, 'T'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST 

START_TEST(sprintf_9_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "g %c";
  ck_assert_int_eq(sprintf(str1, str3, '\0'),
                   s21_sprintf(str2, str3, '\0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST 

Suite *test_sprintf_c(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_C=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_3_c);
  tcase_add_test(tc, sprintf_4_c);    
  tcase_add_test(tc, sprintf_5_c);
  tcase_add_test(tc, sprintf_6_c);
  tcase_add_test(tc, sprintf_7_c);
  tcase_add_test(tc, sprintf_8_c);
  tcase_add_test(tc, sprintf_9_c);

  suite_add_tcase(s, tc);
  return s;
}
