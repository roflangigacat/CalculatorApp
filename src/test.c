#include <check.h>

#include "SmartCalc.h"

#define PRECISION 1e-07

START_TEST(test_1) {
  char check_str[256] = "cos5+sin10";
  double result = calculate(check_str, 0);
  double calc_in_c = (cos(5) + sin(10));
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

START_TEST(test_2) {
  char check_str[256] = "cos5+sin10+tanx";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = (cos(5) + sin(10) + tan(10));
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

START_TEST(test_3) {
  char check_str[256] = "cos5+sin10+tanx";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = (cos(5) + sin(10) + tan(10));
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

START_TEST(test_4) {
  char check_str[256] = "-x";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = -10;
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

START_TEST(test_5) {
  char check_str[256] = "18 * 78 - 534 + 321 / 100";
  char x = 10;
  double result = (int)calculate(check_str, x);
  double calc_in_c = 18 * 78 - 534 + 321 / 100;
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

START_TEST(test_6) {
  char check_str[256] = "cos(0)+tan(2.0)";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = cos(0) + tan(2.0);
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

START_TEST(test_7) {
  char check_str[256] = "cos(10) * sin(20) - sqrt(50) + tan(60)";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = cos(10) * sin(20) - sqrt(50) + tan(60);
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

START_TEST(test_8) {
  char check_str[256] = "acos10";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = acos(10);
  ck_assert_float_nan(result); // NAN
  ck_assert_float_nan(calc_in_c);
}
END_TEST

START_TEST(test_9) {
  char check_str[256] = "asin10";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = asin(10);
  ck_assert_float_nan(result); // NAN
  ck_assert_float_nan(calc_in_c);
}
END_TEST

START_TEST(test_10) {
  char check_str[256] = "atan10";
  char x = 10;
  double result = calculate(check_str, x);
  double calc_in_c = atan(10);
  ck_assert_double_eq_tol(result, calc_in_c, PRECISION);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);
  tcase_add_test(tc1_1, test_7);
  tcase_add_test(tc1_1, test_8);
  tcase_add_test(tc1_1, test_9);
  tcase_add_test(tc1_1, test_10);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}