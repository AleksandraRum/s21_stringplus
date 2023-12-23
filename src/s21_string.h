#ifndef s21_string
#define s21_string

#include <dirent.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define BUFFER 10000
#define s21_size_t unsigned long long
#define s21_NULL (void*)0

typedef struct
{
	int type;
	int minus;
	int zero;
	int star;
	int precision;		
	int is_precision;
	int plus;
	int space;
	int hash;
	int length;	
	int width;	
	int error;
}Flags;

void *s21_memcpy (void *destination, const void *source, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memset(void *str, int c, size_t n);
int s21_sprintf(char* str, const char* format, ...);
char* spec_decimal(long long int var_len, Flags flags, char *str);
int s21_itoa(Flags flags, long long int var_len, size_t size, char *decimal_str);
void parsing_func(char* str, const char* format, Flags flags, va_list* args);
//long long int handle_h_l(Flags *flags, va_list* args, const char* format);
const char *set_flags(const char* format, Flags* flags);
const char *get_width_accuracy(const char* format, Flags* flags, va_list args);
const char *set_length(const char* format, Flags* flags);
char* spec_float(double var_len, Flags flags, char *str);
char *s21_utoa(Flags flags, long int fract, long int integ, char *fract_str, char *buf, size_t size_fr, double var_len, int x);


#endif



