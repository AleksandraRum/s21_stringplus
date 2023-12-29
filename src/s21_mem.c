#include "s21_string.h"


void *s21_memcpy (void *dest, const void *src, s21_size_t n)
{
    char *d = dest;
    const char *s = src;
    for (s21_size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return dest;
}
void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *res = s21_NULL;
  const char *arr = str;
  for (s21_size_t i = 0; i < n; i++) {
    if (arr[i] == c) {
      res = (char *)arr + i;
      break;
    }
  }

  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  const char *arr1 = str1;
  const char *arr2 = str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (arr1[i] != arr2[i]) {
      res = arr1[i] - arr2[i];
      break;
    }
  }
  return res;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *arr = str;
  for (s21_size_t i = 0; i < n; i++) {
    arr[i] = c;
  }
  return str;
}
