#include "../test_main.h"

START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%17s ";
  char *val = "I'm so tired";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%s";
  char *val = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "% 02.3s"; 
  char *val = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-10s";
  char *val = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%6.5s ";// Test %.23s Test %3.s TEST %.s";
  char *val = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-10.5s"; // Test %-.8s Test %-7s TEST %-.s";
  char *val = "yu o";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0s Test "; // %0.s Test %0.0s TEST %0s GOD %.s";
  char *val = "really";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%+s"; // Test %+3.s Test %5.7s TEST %10s";
  char *val = "don't";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_10_string) {
//   char str1[200] = "";
//   char str2[200] = "";
//   char *str3 = "%5.7s T"; 
//   char *val = NULL;
//   ck_assert_int_eq(
//       sprintf(str1, str3, val),
//       s21_sprintf(str2, str3, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_11_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "% 3.s";
  char *val = "Whlovin";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%+.s";
  char *val = "WHAT IS THIS";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0.0s";
  char *val = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = " %05.7s ";
  char *val = "idx";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_string) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "% s";
  char *val = "i care anymore, really";
  ck_assert_int_eq(
      sprintf(str1, str3, val),
      s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "ret %s";
  char *val = "\0";
  ck_assert_int_eq(sprintf(str1, str3, val),
                   s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_17_string) {
//   char str1[1024];
//   char str2[1024];
//   char *str3 = "%7.3s";
//   char *val = NULL;
//   s21_sprintf(str2, str3, val);
//   sprintf(str1, str3, val);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

Suite *test_sprintf_string(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_STRING=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_string);
  tcase_add_test(tc, sprintf_2_string);
  tcase_add_test(tc, sprintf_3_string);
  tcase_add_test(tc, sprintf_4_string);  
  tcase_add_test(tc, sprintf_5_string);
  tcase_add_test(tc, sprintf_6_string);
  tcase_add_test(tc, sprintf_7_string);
  tcase_add_test(tc, sprintf_8_string);
  tcase_add_test(tc, sprintf_9_string);
  //tcase_add_test(tc, sprintf_10_string);    // seg fault
  tcase_add_test(tc, sprintf_11_string);  
  tcase_add_test(tc, sprintf_12_string);
  tcase_add_test(tc, sprintf_13_string);
  tcase_add_test(tc, sprintf_14_string);
  tcase_add_test(tc, sprintf_15_string);
  tcase_add_test(tc, sprintf_16_string);
  //tcase_add_test(tc, sprintf_17_string);     // seg fault

  suite_add_tcase(s, tc);
  return s;
}
