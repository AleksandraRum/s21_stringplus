#include "../test_main.h"

START_TEST(sprintf_1_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%ld Test";
  int val = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%hd est";
  int val = 3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%3d ";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0.d Tes";
  int val = -712;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%6.5d";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-10.5d Te";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0d Tes";
  int val = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "st %+3.d";
  int val = -3015;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "r %.d ";
  int val = 20;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "% 3.d fd";
  int val = -8899;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "KI %+.d";
  int val = 91918;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_signed) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%5.7d TEST";
  int val = -32311;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_14_signed) {
//   char str1[200] = "";
//   char str2[200] = "";
//   char *str3 = "Tes %- 15d";
//   int val = 3231;
//   ck_assert_int_eq(sprintf(str1, str3, val),
//                    s21_sprintf(str2, str3, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_15_signed) {
  char str1[4096] = "";
  char str2[4096] = "";

  ck_assert_int_eq(sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   s21_sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_signed(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_SIGNED=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_signed);
  tcase_add_test(tc, sprintf_2_signed);
  tcase_add_test(tc, sprintf_3_signed);
  tcase_add_test(tc, sprintf_4_signed);
  tcase_add_test(tc, sprintf_5_signed);
  tcase_add_test(tc, sprintf_6_signed);
  tcase_add_test(tc, sprintf_7_signed);
  tcase_add_test(tc, sprintf_8_signed);
  tcase_add_test(tc, sprintf_9_signed);
  tcase_add_test(tc, sprintf_10_signed);
  tcase_add_test(tc, sprintf_11_signed);
  tcase_add_test(tc, sprintf_12_signed);
  tcase_add_test(tc, sprintf_13_signed);
  // tcase_add_test(tc, sprintf_14_signed);
  tcase_add_test(tc, sprintf_15_signed);
  suite_add_tcase(s, tc);
  return s;
}
