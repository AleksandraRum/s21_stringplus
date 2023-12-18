#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "s21_string.h"




int s21_sprintf(char* str, const char* format, ...)
{
    Flags flags  = {0};
    va_list list;
    va_start(list, format);
    char* ptr = str;
    char specif[18] = "diouxXcsnpfFeEgG%";
    long long int var_len;
    while (*format)
    {
        if (*format == '%')
		{
			format++;
            format = set_flags(format, &flags); 
            format = get_width_accuracy(format, &flags, list);  
            format = set_length(format, &flags); 
            while (!strchr(specif, *format))	
				format++;					
			parsing_func(str, format, flags, &list);
            str = str + strlen(str);
        }
        else	
		{
			*str = *format;
            
			str++;
            
		}
		format++;	
        
	}
    //printf("%s\n", str);
	*str = '\0';
    //printf("%s\n", str);
	va_end(list);
    //printf("%c\n", *str);
	return (str - ptr);
}

const char *set_flags(const char* format, Flags* flags) {		
	for (size_t i = 0; format[i] != '\0'; i++)
	{
		switch (format[i])
		{
		case '-':
			flags->minus = 1;		break;
		case '+':
			flags->plus = 1;		break;
		case ' ':
			flags->space = 1;		break;
		case '#':
			flags->hash = 1;		break;
		case '0':
			flags->zero = 1;		break;
		default:  break;
		}
	}
	if (flags->space && flags->plus)  flags->space = 0; 
	if (flags->minus && flags->zero)  flags->zero = 0; 

    return format;
}

int s21_is_digit(int c) { return (c >= '0' && c <= '9'); }
int s21_get_number(char *num_buff) {
	int width = 0;
	for (int i = 0; i < strlen(num_buff); i++){
	width *= 10;
	width += num_buff[i] - '0';
	}
	return width;
}
const char *get_width_accuracy(const char* format, Flags* flags, va_list args)
{

    char num_buff[100] = "";
	char pres_buff[100] = "";
	bool was_dot = false;
	const char* ptr1 = format;
	
	
	int counter = 0;
    if (strchr(format, '.') != NULL) 
	{
		was_dot = true;
		flags->is_precision = 1;
	}	
	int dot = (strchr(format, '.')) - ptr1;
    if (was_dot == true)
	{
	    for (size_t i = 0; format[i] != '.'; i++)
	    {
			
			if (s21_is_digit(format[i])) {
					char buf[2] = "";
					buf[0] = format[i];
					strcat(num_buff, buf);
					flags->width = s21_get_number(num_buff);
            }
            if (format[i] == '*'){
                flags->width = va_arg(args, int);
                   
            }    
				
			if (flags->width < 0)
			{
				flags->zero = 0;
				flags->width *= -1;
				flags->minus = 1;
			}
			
		}
		for (int i = dot; format[i] != '\0'; i++)    

        {
		if (s21_is_digit(format[i])) {
			char buf[2] = "";
			buf[0] = format[i];
			strcat(pres_buff, buf);
			flags->precision = s21_get_number(pres_buff);
                   
        }
				
        if (format[i] == '*'){
        flags->precision = va_arg(args, int);
        }   
		counter = i; 
	    
	    }
	}
	else {
		for (size_t i = 0; format[i] != '\0'; i++)
		{
			if (s21_is_digit(format[i])) {
				char buf[2] = "";
				buf[0] = format[i];
				strcat(num_buff, buf);
				flags->width = s21_get_number(num_buff);   
            }
				
            if (format[i] == '*') flags->width = va_arg(args, int);  
				
				
			if (flags->width < 0)
			{
				flags->zero = 0;
				flags->width *= -1;
				flags->minus = 1;
			}
		
		counter = i; 
		}
	}
					
	format = format + counter;
    return format;
}

const char *set_length(const char* format, Flags* flags)
{
	for (size_t i = 0; format[i] != '\0'; i++)
	{
		if ((format[i] == 'h' || format[i] == 'l') &&
			(format[i + 1] == 'i' || format[i + 1] == 'd' ||
				format[i + 1] == 'o' || format[i + 1] == 'u' ||
				format[i + 1] == 'x' || format[i + 1] == 'X' ||
				format[i + 1] == '%')) {
			flags->length = format[i];
            format++;
		}
		else if (format[i] == 'L' &&
			(format[i + 1] == 'e' || format[i + 1] == 'E' ||
				format[i + 1] == 'f' || format[i + 1] == 'g' ||
				format[i + 1] == 'G' || format[i + 1] == '%' ||
				format[i + 1] == 'F')) {
			flags->length = format[i];
            format++;
		}
	}
	return format;
}


long long int handle_h_l(Flags *flags, va_list* args, const char* format)		
{
	long long int temp;
	if (*format == 'd')
	{
		temp = va_arg(*args, int);
		if (flags->length == 'h') {
			if (temp > 32767 || temp < -32767) 
				flags->error = 1;
		}
		else if (flags->length == 'l') {
			if (temp > 2147483647 || temp < -2147483647)
				flags->error = 1;
		}
	}
	/*else if (*format == 'x' || *format == 'X' || *format == 'o' || *format == 'u')
	{
		temp = va_arg(*args, unsigned long int);
		if (flags->length == 'h') {
			if (temp > 65535) {
				flags->error = 1;
			}
		}
		else if (flags->length == 'l') {
			if (temp > 4294967295)
				flags->error = 1;
		}
	}*/

	return temp;
}

void parsing_func(char* str, const char* format, Flags flags, va_list* args) {	
	long long int var_len = 0;
    switch (*format)
    {
    case 'd':	
	{
		var_len = handle_h_l(&flags, args, format);
		str = spec_decimal(var_len, flags, str);
        
	} break; 
    case 'f': 	
	{
		double var_len = va_arg(*args, double);
		str = spec_float(var_len, flags, str);
	} break;

    default:		printf("error"); break;
    }
}

char* spec_decimal(long long int var_len, Flags flags, char *str)
{
	char *ptr = str;
    size_t size = 0;
    int var = var_len;
    if (var_len < 0) var = -var_len;
    while (var > 0)
    {
        var /= 10;
        size++;
    }

    if((size_t)flags.width > size) size = flags.width;
    if((size_t)flags.precision > size) size = flags.precision;
   
	char *decimal_str = malloc(sizeof(char) * (size));
    int i = s21_itoa(flags, var_len, size, decimal_str);
	
	char c = ' ';
	if (flags.precision > flags.width)  c = '0';
	if ((size_t) i == size)
	{
		if ((flags.space == 1) && (var_len > 0))
		{
			*str = ' ';
			str++;
		}
	}
	
    if (((size_t) i < size) && (flags.precision > flags.width))
	{
		if (flags.plus == 1)
		{
			if (var_len >= 0) *str = '+';
			if (var_len < 0) *str = '-';
			str++;
		}
		if ((flags.plus != 1) && (flags.space == 1))
		{
			if (var_len >= 0) *str = ' ';
			if (var_len < 0) *str = '-';
			str++;
		}
		
		if ((flags.plus != 1) && (flags.space != 1) && (flags.minus == 1))
		{
			if (var_len < 0) 
			{
				*str = '-';
			    str++;
			}
		}
		for (size_t  k = 0; k < (size - (size_t)i); k++)
		{ 
		*str = c;
		str++;
		}
    }

	if (((size_t)i < size) && (flags.precision < flags.width))
	{
	    if (flags.minus != 1)
	    {
	        for (size_t k = 0; k < (size - (size_t)i); k++)
		    { 
		        *str = c;
			    str++;
		    }
	    }
		if ((flags.minus == 1 ) && (flags.space == 1) && (var_len >= 0))
		{
		    *str = ' ';
			str++;
		}
		
	}
	for (int j = i - 1; j >= 0; j--)
    {
        *str = decimal_str[j];
        str++;
    }
	if (((size_t)i < size) && (flags.minus == 1) && (flags.precision < flags.width))
	{
		while (size > (size_t) (str - ptr))
		{
            *str = ' ';
		    str++;
		}
	}
	
    if (decimal_str != NULL) free(decimal_str);
	decimal_str = NULL;
    return str;
}

int s21_itoa(Flags flags, long long int var_len, size_t size, char *decimal_str)
{
    int i;
	
    int len = var_len;
    if (var_len < 0) 
        len = -len;         
        i = 0;
    do {     
        decimal_str[i++] = len % 10 + '0'; 
        } 
    while ((len /= 10) > 0.1); 

	if ((flags.plus == 1) && (var_len >= 0) && (flags.precision < flags.width) && ((size_t)i <= size)) decimal_str[i++] = '+';
	if ((var_len < 0) && ((size_t)i == size)) decimal_str[i++] = '-';
	if ((flags.minus == 1) && (var_len < 0) && ((size_t)i == size)) decimal_str[i++] = '-';
	if (((size_t)i < size) && (var_len < 0) && ((flags.precision < flags.width) || (((size_t)flags.precision < size) && ((size_t)flags.width < size)))) decimal_str[i++] = '-';
    return i;
}


char* spec_float(double var_len, Flags flags, char *str)
{
	double copy_var = var_len;

    long int integ, fract;
	//float fract;
	integ = (int) copy_var;
	double fract1 = copy_var - integ;
	//float fract2 = fract1;
	int j = 0;
	while ((fract1 - (long int) fract1) != 0) 
	{
		fract1 *= 10;
		j++;
	}
	fract = (long int) fract1;
	//printf("%ld\n", fract);
	long int copy_int = integ;
	long int copy_fr = fract;
	//printf("%ld\n", fract);
	size_t size_i = 0;
	size_t size_fr = 0;
	while (copy_int > 0.1)
    {
        copy_int /= 10;
        size_i++;
    }
	//printf("%zu\n", size_i);
	while (copy_fr > 0.1)
    {
        copy_fr /= 10;
        size_fr++;
    }
	//printf("%zu\n", size_fr);
	size_t size = size_fr + size_i;
	size++;
	//printf("%zu\n", size);
    if((size_t)flags.width > size) size = flags.width;
    if((size_t)flags.precision > 0) size = size_i + 1 + flags.precision;
	if ((flags.precision == 0) && (flags.is_precision == 0)) size = size_i + 7;
	if ((flags.precision == 0) && (flags.is_precision == 1)) size = size_i;
	//printf("%zu\n", size);
    char *fract_str = malloc(sizeof(char) * size);
	int i = s21_utoa(flags, fract, integ, size, fract_str, size_i);

	for (int j = i - 1; j >= 0; j--)
    {
        *str = fract_str[j];
        str++;
    }
	//printf("%s\n", fract_str);
	if (fract_str != NULL) free(fract_str);
	//fract_str = NULL;
	
    return str;
}
int s21_utoa(Flags flags, long int fract, long int integ, size_t size, char *fract_str, size_t size_i)
{
    int i = 0;
    long int copy_int = integ;
	long int copy_fr = fract;
	printf("%ld\n", copy_fr);
    if (integ < 0) 
        copy_int = -copy_int;     
	if ((flags.precision > 0) || ((flags.precision == 0) && (flags.is_precision == 0))) {
		do {     
        fract_str[i] = copy_fr % 10 + '0'; 
        i++;
		printf("%c\n", fract_str[i]);
        } 
        while (i < (size - size_i - 1)); 
		fract_str[i++] = '.';
	}
		do {     
        fract_str[i++] = copy_int % 10 + '0'; 
        } 
        while ((copy_int /= 10) > 0.1); 
	
	//printf("%d\n", i);
	return i;

}
