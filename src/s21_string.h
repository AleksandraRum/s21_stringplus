#ifndef s21_string
#define s21_string

#include <dirent.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER 10000
#define s21_size_t unsigned long long
#define s21_NULL (void*)0

void *s21_memcpy (void *destination, const void *source, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memset(void *str, int c, size_t n);

#endif