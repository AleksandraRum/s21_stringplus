#include "test_main.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {test_to_upper(),
                              test_to_lower(),
                              test_insert(),
                              test_trim(),
                              s21_NULL};

  for (int i = 0; s21_string_test[i] != s21_NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}