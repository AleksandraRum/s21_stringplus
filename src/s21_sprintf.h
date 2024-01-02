#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "s21_string.h"

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

int s21_sprintf(char* str, const char* format, ...);
char* spec_decimal(long long int var_len, Flags flags, char *str);
int s21_itoa(Flags flags, long long int var_len, s21_size_t size, char *decimal_str,char *buf);
void parsing_func(char* str, const char* format, Flags flags, va_list* args);
const char *set_flags(const char* format, Flags* flags);
const char *get_width_accuracy(const char* format, Flags* flags, va_list args);
const char *set_length(const char* format, Flags* flags);
char* spec_float(double var_len, Flags flags, char *str);
char *s21_utoaf(Flags flags, long int fract, long int integ, char *fract_str, char *buf, double var_len, int x);
char* spec_char(const char c, Flags* flags, char* str);
void ch2str(const char c, char* str);
char* space2str(int width, int lenght, int zero_fill, char* str);
char* spec_string(char* s, Flags* flags, char* str);
char* spec_unsign(uint64_t un, Flags* flags, char* str);
char* s21_utoa(uint64_t n, int len);
int get_len_num(uint64_t num);
char* spec_pointer(void* pointer, Flags* flags, char* str);
int s21_is_digit(int c); 



