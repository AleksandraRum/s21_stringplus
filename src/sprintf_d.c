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
			Flags flags  = {0};
			format++;
			while ((*format == '+' || *format == '-' || *format == ' ' || *format == '#'))
			{
				format = set_flags(format, &flags); 
				format++;
			}
            format = get_width_accuracy(format, &flags, list);  
			format = set_length(format, &flags);
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
   
	*str = '\0';
	va_end(list);
	return (str - ptr);
}

const char *set_flags(const char* format, Flags* flags) {		
	{
		switch (*format)
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

int s21_is_digit(int c) 
{ 
	int x = 0;
	if (c >= '0' && c <= '9') x = 1;
	return x; 
}
int s21_get_number(char *num_buff) {
	int width = 0;
	for (size_t i = 0; i < strlen(num_buff); i++){
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
			counter = i;
		}
		for (int i = counter + 2; s21_is_digit(format[i]) != 0; i++)    
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
		counter = counter + i + 1; 
	    }
	}
	else {
		for (size_t i = 0; s21_is_digit(format[i]) != 0; i++)
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
		counter = i + 1; 
		}
	}
					
	format = format + counter;
    return format;
}

const char *set_length(const char* format, Flags* flags)
{
	//printf("%c\n", *format);
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

/*long long int handle_h_l(Flags *flags, va_list* args, const char* format)		
{
	long long int temp;
	if (*format == 'd')
	{
		if (flags->length == 'h') {
			temp = (short)va_arg(*args, int);
			//flags->error = 1;		//if (temp > 32767 || temp < -32767) 
		}
		//else flags->error = 1;
		
		else if (flags->length == 'l') {
			//if (temp > 2147483647 || temp < -2147483647)
			temp = va_arg(*args, long int);
			if (!va_arg(*args, long int)) printf("error");//flags->error = 1;
		}
		else temp = va_arg(*args, int);
		//else flags->error = 1;
	}
	else if (*format == 'x' || *format == 'X' || *format == 'o' || *format == 'u')
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
	}

	return temp;
}*/

void parsing_func(char* str, const char* format, Flags flags, va_list* args) {	
	long int long_len;
	short short_len;
    int var_len;
    switch (*format)
    {
    case 'd':	
	{
		//var_len =  va_arg(*args, int);
		//var_len = handle_h_l(&flags, args, format);
		if (flags.length == 'l') 
		{
			long_len =  va_arg(*args, long int);
			str = spec_decimal(long_len, flags, str);
		}
		if (flags.length == 'h') 
		{
			short_len =  (short) va_arg(*args, int);
			str = spec_decimal(short_len, flags, str);
		}
        else 
		{
			var_len =  va_arg(*args, int);
		    str = spec_decimal(var_len, flags, str);
		}
	} break; 
    case 'f': 	
	{

		double var_len = va_arg(*args, double);
		str = spec_float(var_len, flags, str);
	} break;

    default:		break;
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
	char *decimal_str = malloc(sizeof(char) * (size + 1));
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
		if ((flags.plus != 1) && (flags.space != 1) && (flags.minus != 1) && (var_len < 0))
			{
				*str = '-';
			    str++;
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

	if ((flags.plus == 1) && (var_len >= 0) && (((flags.precision < flags.width) && ((size_t)i < size))||((size_t)i == size))) decimal_str[i++] = '+';
	if ((var_len < 0) && ((size_t)i == size)) decimal_str[i++] = '-';
	if ((flags.minus == 1) && (var_len < 0) && ((size_t)i == size)) decimal_str[i++] = '-';
	if (((size_t)i < size) && (var_len < 0) && ((flags.precision < flags.width) || (((size_t)flags.precision < size) && ((size_t)flags.width < size)))) decimal_str[i++] = '-';
    return i;
}


char* spec_float(double var_len, Flags flags, char *str)
{
	char buf[50] = "";
	double copy_var = var_len;
	if (var_len < 0) copy_var = - var_len;
    long int integ, fract;
	integ = (int) copy_var;
	int x = 6;
    if ((flags.precision > 0)) x = flags.precision;
	double fract1 = roundl((copy_var - integ) * (pow(10, x)));
	if ((flags.precision == 0) && (flags.is_precision)) fract1 = 0;
	fract = ((long int) fract1);
	long int copy_int = integ;
	long int copy_fr = fract;
	size_t size_i = 0;
	size_t size_fr = 0;
	while (copy_int > 0.1)
    {
        copy_int /= 10;
        size_i++;
    }
	while (copy_fr > 0.1)
    {
        copy_fr /= 10;
        size_fr++;
    }
	size_t size = size_fr + size_i;
	size++;
	if ((var_len < 0) || (flags.space) || (flags.plus)) size++;
	if ((flags.precision == 0) && (flags.is_precision)) size--;
	
    char *fract_str = malloc(sizeof(char) * (size + 1));
	//printf("%zu\n",size);
	s21_utoa(flags, fract, integ, fract_str, buf, size_fr, var_len, x);
    if (!flags.minus)
	{
    while ((size_t)flags.width > size) 
	{
		*str = ' ';
		str++;
		size++;
	}
	}
	for (size_t i = 0; i < (strlen(buf)); i++)
	{
		*str = buf[i];
		str++;
	}
	 if (flags.minus)
	{
		while ((size_t)flags.width > size) 
	{
		*str = ' ';
		str++;
		size++;
	}
	}
    return str;
}

char* s21_utoa(Flags flags, long int fract, long int integ, char *fract_str, char *buf, size_t size_fr, double var_len, int x)
{
    int i = 0;
    long int copy_int = integ;
	long int copy_fr = fract;
	size_t copy_sf = size_fr;
	//printf("%zu\n",size);
	if ((flags.is_precision == 0) || (flags.precision > 0))
	{
        do {     
        fract_str[i++] = copy_fr % 10 + '0'; 
        } 
        while ((copy_fr /= 10) > 0.1); 
		while (i < x) {
			fract_str[i++] = '0';
		}
		fract_str[i++] = '.';
	}
	do {     
    fract_str[i++] = copy_int % 10 + '0'; 
    } 
    while ((copy_int /= 10) > 0.1); 
	//printf("%zu\n",size);
	
	//printf("%d\n", i);
	
    if (var_len < 0) {
		*buf = '-';
        buf++;
	}
	else if ((var_len > 0) && (flags.plus))
	{
		*buf = '+';
        buf++;
	}
	else if ((var_len > 0) && (flags.space))
	{
		*buf = ' ';
        buf++;
	}
	for (int j = i - 1; j >= 0; j--)
    {
        *buf = fract_str[j];
        buf++;
    }
	
	if (fract_str != NULL) free(fract_str);
	fract_str = NULL;
	//printf("%s\n",fract_str);
	return buf;
}
