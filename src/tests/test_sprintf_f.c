#include "../test_main.h"

START_TEST(sprintf_1_f) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%f TEST!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%.f TES!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "%20.10f"; 
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %5f  ";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "tst: %12.f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %25.5f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %+15.f f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %+ 18.0f ";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num ),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %-26.1f po";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num ),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %-+25.f";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %-26.1f ";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %15.13f!!!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %+ 25.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test:  % -26f !te! ";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %+- 14f !test:!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "test: %- 19f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = " %20f rtu";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "t %25.5f oo!!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = " %- 26f ";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "%+- 10.2f";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "fshgkaljck% 10.12f hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_f) {
  char str1[4096]="";
  char str2[4096]="";

  ck_assert_int_eq(
      s21_sprintf(str1, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_f(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_F=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_f);
  tcase_add_test(tc, sprintf_2_f);
  tcase_add_test(tc, sprintf_3_f);
  tcase_add_test(tc, sprintf_4_f);
  tcase_add_test(tc, sprintf_5_f);
  tcase_add_test(tc, sprintf_6_f);
  tcase_add_test(tc, sprintf_7_f);
  tcase_add_test(tc, sprintf_8_f);
  tcase_add_test(tc, sprintf_9_f);
  tcase_add_test(tc, sprintf_10_f);
  tcase_add_test(tc, sprintf_11_f);
  tcase_add_test(tc, sprintf_12_f);
  tcase_add_test(tc, sprintf_13_f);
  tcase_add_test(tc, sprintf_14_f);
  tcase_add_test(tc, sprintf_15_f);
  tcase_add_test(tc, sprintf_16_f);
  tcase_add_test(tc, sprintf_17_f);
  tcase_add_test(tc, sprintf_18_f);
  tcase_add_test(tc, sprintf_19_f);
  tcase_add_test(tc, sprintf_20_f);
  tcase_add_test(tc, sprintf_21_f);
  tcase_add_test(tc, sprintf_22_f);
  suite_add_tcase(s, tc);
  return s;
}
