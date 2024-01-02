#include "../test_main.h"

START_TEST(sprintf_1_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %i Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%li Test";
  int val = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_signed_i) {
  char str1[100];
  char str2[100];
  char str1[100] = "";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
}
END_TEST

START_TEST(sprintf_4_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%3i ";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0.i Tes";
  int val= -712;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%6.5i";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-10.5i Te";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0i Tes"; 
  int val = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "st %+3.i";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "r %.i ";
  int val = 20;
  ck_assert_int_eq(
      sprintf(str1, str3, val),
      s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "% 3.i fd";
  int val = -8899;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "KI %+.i";
  int val = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%5.7i TEST";
  int val = -32311;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_signed_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "Tes %- 15i";
  int val = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_signed_i(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_SIGNED_I=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_signed_i);
  tcase_add_test(tc, sprintf_2_signed_i);
  tcase_add_test(tc, sprintf_3_signed_i);
  tcase_add_test(tc, sprintf_4_signed_i);
  tcase_add_test(tc, sprintf_5_signed_i);
  tcase_add_test(tc, sprintf_6_signed_i);
  tcase_add_test(tc, sprintf_7_signed_i);
  tcase_add_test(tc, sprintf_8_signed_i);
  tcase_add_test(tc, sprintf_9_signed_i);
  tcase_add_test(tc, sprintf_10_signed_i);
  tcase_add_test(tc, sprintf_11_signed_i);
  tcase_add_test(tc, sprintf_12_signed_i);
  tcase_add_test(tc, sprintf_13_signed_i);
  tcase_add_test(tc, sprintf_14_signed_i);

  suite_add_tcase(s, tc);
  return s;
}
