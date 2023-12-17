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
#define s21_NULL (void *)0

void *s21_memcpy(void *destination, const void *source, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memset(void *str, int c, size_t n);

char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char* str, const char* sym);
char* s21_strpbrk(const char* str, const char* sym);
char *s21_strchr(const char *str, int symbol);
int s21_strncmp(const char *str1, const char *str2, s21_size_t num);
char* s21_strncpy( char * dest, const char * source, s21_size_t num );
char *s21_strstr(const char *dest, const char *source) ;
char *s21_strcpy(char *dest, const char *source);
s21_size_t s21_strspn(const char* str, const char* sym);
int* create_delim(const char* delim);
char* s21_strtok(char* str, const char* delim);

#endif