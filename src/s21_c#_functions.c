#include "s21_c#_functions.h"

void *s21_to_lower(const char *str) {
  char *str_copy = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len = s21_strlen(str);
    str_copy = (char *)malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str_copy[i] = (str[i] - 'A') + 'a';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

void *s21_to_upper(const char *str) {
  char *str_copy = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len = s21_strlen(str);
    str_copy = (char *)malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_copy[i] = (str[i] - 'a') + 'A';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t final_len = src_len + str_len;
    if (str_len >= start_index) {
      res = (char *)malloc(sizeof(char) * (final_len + 1));
    }
    if (res) {
      s21_size_t j = 0, k = 0;
      for (s21_size_t i = 0; i < final_len; i++) {
        if (i >= start_index && j < str_len) {
          res[i] = str[j];
          j++;
        } else {
          res[i] = src[k];
          k++;
        }
      }
      res[final_len] = '\0';
    }
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src != s21_NULL) {
    if (trim_chars != s21_NULL && *trim_chars) {
      s21_size_t src_len = s21_strlen(src);
      s21_size_t trim_len = s21_strlen(trim_chars);
      res = (char *)malloc(sizeof(char) * (src_len + 1));
      if (res) {
        s21_size_t left = 0, right = 0;
        for (s21_size_t i = 0; i < src_len; i++) {
          int flag = 1;
          for (s21_size_t j = 0; j < trim_len; j++) {
            if (src[i] == trim_chars[j]) {
              flag = 0;
            }
          }
          if (flag) {
            left = i;
            i = src_len;
          }
        }
        for (int i = src_len - 1; i >= 0; i--) {
          int flag = 1;
          for (s21_size_t j = 0; j < trim_len; j++) {
            if (src[i] == trim_chars[j]) {
              flag = 0;
            }
          }
          if (flag) {
            right = i;
            i = -1;
          }
        }
        for (s21_size_t i = left; i <= right; i++) {
          res[i - left] = src[i];
        }
        res[right + 1] = '\0';
      }
    }else{
      s21_size_t src_len = s21_strlen(src);
      res = (char *)malloc(sizeof(char) * (src_len + 1));
      for(s21_size_t i = 0; i < src_len; i++){
        res[i] = src[i];
      }
      res[src_len] = '\0';
    }
  }
  return res;
}