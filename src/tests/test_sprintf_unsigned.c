#include "../test_main.h"

START_TEST(sprintf_1_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%u es";
  unsigned int val = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%hu u";
  unsigned int val = 3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%lu re";
  long unsigned int val = 3088675747373646;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%10u ";
  unsigned int val = 3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%6.5u ";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-10.5u ";
  unsigned int val = 3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0u   ";
  unsigned int val = 3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%+u Test ";
  unsigned int val = 3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-u gh";
  unsigned int val = 0;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "% u Test ";
  unsigned int val = 32;

  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%+u ";
  unsigned int val = 42949;

  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%+.u";
  unsigned int val = 4294;

  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%06u ";
  unsigned int val = 8899;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%+3.u ";
  unsigned int val = 429;

  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%- 15u sda";
  unsigned int val = -3231;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_unsigned) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-.u";
  unsigned int val = -3231;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_unsigned(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_UNSIGNED=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_unsigned);
  tcase_add_test(tc, sprintf_2_unsigned);
  tcase_add_test(tc, sprintf_3_unsigned);
  tcase_add_test(tc, sprintf_4_unsigned);
  tcase_add_test(tc, sprintf_5_unsigned);
  tcase_add_test(tc, sprintf_6_unsigned);
  tcase_add_test(tc, sprintf_7_unsigned);
  tcase_add_test(tc, sprintf_8_unsigned);
  tcase_add_test(tc, sprintf_9_unsigned);
  tcase_add_test(tc, sprintf_10_unsigned);
  tcase_add_test(tc, sprintf_11_unsigned);
  tcase_add_test(tc, sprintf_12_unsigned);
  tcase_add_test(tc, sprintf_13_unsigned);
  tcase_add_test(tc, sprintf_14_unsigned);
  tcase_add_test(tc, sprintf_15_unsigned);
  tcase_add_test(tc, sprintf_16_unsigned);
  tcase_add_test(tc, sprintf_17_unsigned);
  tcase_add_test(tc, sprintf_18_unsigned);

  suite_add_tcase(s, tc);
  return s;
}
