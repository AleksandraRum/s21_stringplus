#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  unsigned int dest_length = 0;
  unsigned int src_length = 0;
  while (dest[dest_length] != '\0') {
    dest_length++;
  }
  while (src[src_length] != '\0' && src_length < n) {
    dest[dest_length + src_length] = src[src_length];
    src_length++;
  }
  dest[dest_length + src_length] = '\0';
  return dest;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0, res = 0;
  while (str[i] != '\0') {
    res++;
    i++;
  }
  return res;
}
s21_size_t s21_strcspn(const char *str, const char *sym) {
  s21_size_t cnt = 0;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (s21_strchr(sym, str[i]) == s21_NULL)
      cnt++;
    else
      break;
  }
  return cnt;
}
char *s21_strpbrk(const char *str, const char *sym) {
  s21_size_t pos = 0, find = 0;
  char *ptr = (char *)str;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (s21_strchr(sym, ptr[i]) != s21_NULL) {
      find = 1;
      break;
    }
    pos++;
  }
  return (find == 1 ? ptr + pos : s21_NULL);

}
char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  while ((*str != '\0') && (*str != c)) {
    str++;
  }
  if (*str == c) {
    res = (char *)str;
  }
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  unsigned char c1, c2;
  while (n) {
    c1 = *str1++;
    c2 = *str2++;
    if (c1 != c2) return c1 - c2;
    if (!c1) break;
    n--;
  }
  return 0;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  return dest;
}

char *s21_strstr(const char *dest, const char *src) {
  char *position = s21_NULL;
  int err = 0;
  char *cdest = (char *)dest;
  if (s21_strlen(src) == 0) {
    position = cdest;
  } else {
    for (int i = 0; i < (int)s21_strlen(cdest); i++) {
      if (cdest[i] == src[0]) {
        position = &cdest[i];
        for (int j = i, k = 0; j < (int)s21_strlen(src) + i; j++, k++) {
          if (cdest[j] != src[k]) {
            err = 1;
          }
        }
        if (err == 0) {
          break;
        } else {
          position = s21_NULL;
          err = 0;
          continue;
        }
      }
    }
  }
  return position;
}

char *s21_strcpy(char *dest, const char *source) {
  if (dest == s21_NULL) {
    return s21_NULL;
  }
  char *ptr = dest;
  while (*source != '\0') {
    *dest = *source;
    dest++;
    source++;
  }
  *dest = '\0';
  return ptr;
}

s21_size_t s21_strspn(const char *str, const char *sym) {
  s21_size_t cnt = 0;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (s21_strchr(sym, str[i]) != s21_NULL) cnt++;
  }
  return cnt;
}

char *olds;
char *s21_strtok(char *str, const char *delim) {
  char *token = s21_NULL;
  if (str == s21_NULL) str = olds;

  /* Scan leading delimiters.  */
  str += s21_strspn(str, delim);  // handles possible trailing delims
  if (*str == '\0') {
    olds = str;
    return s21_NULL;
  }

  /* Find the end of the token.  */
  token = str;
  str = s21_strpbrk(token, delim);
  if (str == s21_NULL) {
    /* This token finishes the string.  */
    olds = s21_memchr(token, '\0', 1024);
  } else {
    /* Terminate the token and make OLDS point past it.  */
    *str = '\0';
    olds = str + 1;
  }
  return token;
}

char *s21_strcat(char *destination, char *addition) {
  int str1_length = s21_strlen(destination);
  int str2_length = s21_strlen(addition);

  for (int i = 0; i <= str2_length; i++) {
    destination[str1_length + i] = addition[i];
  }

  return destination;
}
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

