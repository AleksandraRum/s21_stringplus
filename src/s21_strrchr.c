#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  int i = 0;
  for (; str[i]; i++) {
    if (str[i] == c) {
      result = (char *)str + i;
    }
  }
  if (c == '\0') {
    result = (char *)str + i;
  }
  return result;
}