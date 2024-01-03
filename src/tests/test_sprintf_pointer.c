#include "../test_main.h"

START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %p Test";
  char *val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%p Te";
  char *val = "0p91ba123f";

  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%p ";
  unsigned short int *val = (void *)22600;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%p Test";
  long int *val = (void *)3088675747373646;
  // long long int* val2 = (void*)33030030303;
  // unsigned short int* val3 = (void*)22600;
  // unsigned char* val4 = (void*)120;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%12p";
  char *val = "3015";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_pointer) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%6.5p";
  char *val = "3015";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_pointer) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%-10.5p Test";
  char *val = "3015";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_pointer) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%0p Test";
  char *val = "3015";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_pointer) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%+p Te";
  char *val = "3015";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_10_pointer) {
//   char str1[200] = "";
//   char str2[200] = "";
//   char* str3 = "y %5.7p TEST"; // %.p % .p";
//   char* val = 0;
//   ck_assert_int_eq(
//       sprintf(str1, str3, val),
//       s21_sprintf(str2, str3, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_11_pointer) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "% p t";
  char *val = "8899";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_12_pointer) {
//   char str1[200] = "";
//   char str2[200] = "";
//   char* str3 = "poi %+.p";
//   char* val = "91918";
//   ck_assert_int_eq(sprintf(str1, str3, val),
//                    s21_sprintf(str2, str3, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_13_pointer) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%06p Te";
  char *val = "32";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_pointer(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_POINTER=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_pointer);
  tcase_add_test(tc, sprintf_2_pointer);
  tcase_add_test(tc, sprintf_3_pointer);
  tcase_add_test(tc, sprintf_4_pointer);
  tcase_add_test(tc, sprintf_5_pointer);
  tcase_add_test(tc, sprintf_6_pointer);
  tcase_add_test(tc, sprintf_7_pointer);
  tcase_add_test(tc, sprintf_8_pointer);
  tcase_add_test(tc, sprintf_9_pointer);
  // tcase_add_test(tc, sprintf_10_pointer);
  tcase_add_test(tc, sprintf_11_pointer);
  // tcase_add_test(tc, sprintf_12_pointer);
  tcase_add_test(tc, sprintf_13_pointer);

  suite_add_tcase(s, tc);
  return s;
}
