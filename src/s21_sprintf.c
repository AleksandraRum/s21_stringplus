#include "s21_sprintf.h"

#include <stdarg.h>
#include <stdbool.h>

int s21_sprintf(char* str, const char* format, ...) {
  va_list list;
  va_start(list, format);
  char* ptr = str;
  while (*format) {
    if (*format == '%') {
      Flags flags = {0};
      format++;
      while ((*format == '+' || *format == '-' || *format == ' ' ||
              *format == '#')) {
        format = set_flags(format, &flags);
        format++;
      }
      format = get_width_accuracy(format, &flags, list);
      format = set_length(format, &flags);
      parsing_func(str, format, flags, &list);
      str = str + strlen(str);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  *str = '\0';
  va_end(list);
  return (str - ptr);
}

const char* set_flags(const char* format, Flags* flags) {
  {
    switch (*format) {
      case '-':
        flags->minus = 1;
        break;
      case '+':
        flags->plus = 1;
        break;
      case ' ':
        flags->space = 1;
        break;
      case '#':
        flags->hash = 1;
        break;
      case '0':
        flags->zero = 1;
        break;
      default:
        break;
    }
  }
  if (flags->space && flags->plus) flags->space = 0;
  if (flags->minus && flags->zero) flags->zero = 0;
  return format;
}

int s21_is_digit(int c) {
  int x = 0;
  if (c >= '0' && c <= '9') x = 1;
  return x;
}
int s21_get_number(char* num_buff) {
  int width = 0;
  for (s21_size_t i = 0; i < s21_strlen(num_buff); i++) {
    width *= 10;
    width += num_buff[i] - '0';
  }
  return width;
}
const char* get_width_accuracy(const char* format, Flags* flags, va_list args) {
  char num_buff[100] = "";
  char pres_buff[100] = "";
  bool was_dot = false;
  int x = 0;
  int counter = 0;
  int count_1 = 0;
  for (int i = 0; (format[i] < 97) || (format[i] > 122); i++) {
    if (format[i] == '.') {
      was_dot = true;
      flags->is_precision = 1;
      break;
    }
  }
  if (*format == '.') x++;
  if (was_dot == true) {
    if (x == 0) {
      for (s21_size_t i = 0; format[i] != '.'; i++) {
        if (s21_is_digit(format[i])) {
          char buf[2] = "";
          buf[0] = format[i];
          strcat(num_buff, buf);
        }
        flags->width = s21_get_number(num_buff);
        counter = i;
      }
      if (*format == '*') {
        flags->width = va_arg(args, int);
        counter = 0;
      }
    } else
      counter = -1;
    if ((!s21_is_digit(format[counter + 2])) && format[counter + 2] != '*')
      counter = counter + 2;
    if (format[counter + 2] == '*') {
      flags->precision = va_arg(args, int);
      counter = counter + 3;
    }
    for (int i = counter + 2; s21_is_digit(format[i]) != 0; i++) {
      if (s21_is_digit(format[i])) {
        char buf[2] = "";
        buf[0] = format[i];
        strcat(pres_buff, buf);
      }
      flags->precision = s21_get_number(pres_buff);
      count_1 = i;
    }
    if ((x > 0) && (count_1 != 0))
      counter = counter + count_1 + 2;
    else if ((flags->width > 9) || (count_1 == 0))
      counter = counter + count_1;
    else
      counter = counter + count_1 + 1;
  } else {
    for (s21_size_t i = 0; s21_is_digit(format[i]) != 0; i++) {
      if (s21_is_digit(format[i])) {
        char buf[2] = "";
        buf[0] = format[i];
        strcat(num_buff, buf);
      }
      flags->width = s21_get_number(num_buff);
      counter = i + 1;
    }
    if (*format == '*') {
      flags->width = va_arg(args, int);
      counter = 1;
    }
  }
  format = format + counter;
  return format;
}
const char* set_length(const char* format, Flags* flags) {
  for (s21_size_t i = 0; format[i] != '\0'; i++) {
    if ((format[i] == 'h' || format[i] == 'l') &&
        (format[i + 1] == 'i' || format[i + 1] == 'd' || format[i + 1] == 'o' ||
         format[i + 1] == 'u' || format[i + 1] == 'x' || format[i + 1] == 'X' ||
         format[i + 1] == '%')) {
      flags->length = format[i];
      format++;
    } else if (format[i] == 'L' &&
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

void parsing_func(char* str, const char* format, Flags flags, va_list* args) {
  long int long_len;
  short short_len;
  int var_len;
  switch (*format) {
    case '%':
      str = spec_char('%', &flags, str);
      break;
    case 'd':
    case 'i': {
      if (flags.length == 'l') {
        long_len = va_arg(*args, long int);
        str = spec_decimal(long_len, flags, str);
      } else if (flags.length == 'h') {
        short_len = (short)va_arg(*args, int);
        str = spec_decimal(short_len, flags, str);
      } else {
        var_len = va_arg(*args, int);
        str = spec_decimal(var_len, flags, str);
      }
    } break;
    case 'c': {
      str = spec_char(va_arg(*args, int), &flags, str);
    } break;
    case 'u': {
      str = spec_unsign(va_arg(*args, uint64_t), &flags, str);
    } break;
    case 'p': {
      str = spec_pointer(va_arg(*args, void*), &flags, str);
    } break;
    case 's': {
      str = spec_string(va_arg(*args, char*), &flags, str);
    } break;
    case 'f': {
      double var_len = va_arg(*args, double);
      str = spec_float(var_len, flags, str);
    } break;

    default:
      break;
  }
}

char* spec_decimal(long long int var_len, Flags flags, char* str) {
  char* ptr = str;
  s21_size_t size = 0;
  int var = var_len;
  if (var_len < 0) var = -var_len;
  while (var > 0) {
    var /= 10;
    size++;
  }
  if ((s21_size_t)flags.width > size) size = flags.width;
  if ((s21_size_t)flags.precision > size) size = flags.precision;
  char* decimal_str = malloc(sizeof(char) * (size + 1));
  int i = s21_itoa(flags, var_len, size, decimal_str);
  char c = ' ';
  if (flags.precision >= flags.width) c = '0';
  if (((s21_size_t)i == size) && (flags.space == 1) && (var_len > 0)) {
    *str = ' ';
    str++;
  }
  if (((s21_size_t)i < size) && (flags.precision >= flags.width)) {
    if (flags.plus == 1) {
      if (var_len >= 0) *str = '+';
      if (var_len < 0) *str = '-';
      str++;
    }
    if ((flags.plus != 1) && (flags.space == 1)) {
      if (var_len >= 0) *str = ' ';
      if (var_len < 0) *str = '-';
      str++;
    }
    if ((flags.plus != 1) && (flags.space != 1) && (flags.minus == 1)) {
      if (var_len < 0) {
        *str = '-';
        str++;
      }
    }
    if ((flags.plus != 1) && (flags.space != 1) && (flags.minus != 1) &&
        (var_len < 0)) {
      *str = '-';
      str++;
    }
    for (s21_size_t k = 0; k < (size - (s21_size_t)i); k++) {
      *str = c;
      str++;
    }
  }
  if (((s21_size_t)i < size) && (flags.precision < flags.width)) {
    if (i < flags.precision) {
      int x = flags.width - flags.precision;
      int y = flags.precision - i;
      if (var_len < 0) {
        *str = '-';
        str++;
        x--;
      }
      if (!flags.minus) {
        while (x != 0) {
         
          *str = c;
          str++;
          x--;
        }
      }
      while (y != 0) {
        *str = '0';
        str++;
        y--;
      }
    } else if ((flags.minus == 1) && (flags.space == 1) && (var_len >= 0)) {
      *str = ' ';
      str++;
    } else {
      for (s21_size_t k = 0; k < (size - (s21_size_t)i); k++) {
        *str = c;
        str++;
      }
    }
  }
  if ((flags.is_precision == 1) && (flags.precision == 0) && (var_len == 0)) {
    *str = ' ';
    str++;
  } else {
    for (int j = i - 1; j >= 0; j--) {
      *str = decimal_str[j];
      str++;
    }
  }
  if (((s21_size_t)i < size) && (flags.minus == 1) &&
      (flags.precision < flags.width)) {
    while (size > (s21_size_t)(str - ptr)) {
      *str = ' ';
      str++;
    }
  }
  if (decimal_str != NULL) free(decimal_str);
  decimal_str = NULL;
  return str;
}

int s21_itoa(Flags flags, long long int var_len, s21_size_t size,
             char* decimal_str) {
  int i;

  int len = var_len;
  if (var_len < 0) {
    len = -len;
  }
  i = 0;

  do {
    decimal_str[i++] = len % 10 + '0';
  } while ((len /= 10) > 0.1);

  if ((flags.plus == 1) && (var_len >= 0) &&
      (((flags.precision < flags.width) && ((s21_size_t)i < size)) ||
       ((s21_size_t)i == size)))
    decimal_str[i++] = '+';
  if ((var_len < 0) && ((s21_size_t)i == size)) decimal_str[i++] = '-';
  if ((flags.minus == 1) && (var_len < 0) && ((s21_size_t)i == size))
    decimal_str[i++] = '-';
  if (((s21_size_t)i < size) && (var_len < 0) && ((int)flags.precision < i) &&
      ((int)flags.width > i))
    decimal_str[i++] = '-';
  return i;
}

char* spec_float(double var_len, Flags flags, char* str) {
  char buf[50] = "";
  double copy_var = var_len;
  if (var_len < 0) copy_var = -var_len;
  long int integ, fract;
  integ = (long int)copy_var;
  int x = 6;
  if ((flags.precision > 0)) x = flags.precision;
  double fract1 = roundl((copy_var - integ) * (pow(10, x)));
  if ((flags.precision == 0) && (flags.is_precision)) {
    fract1 = 0;
    integ = roundl(copy_var);
  }
  fract = ((long int)fract1);
  long int copy_int = integ;
  long int copy_fr = fract;
  s21_size_t size_i = 0;
  s21_size_t size_fr = 0;
  while (copy_int > 0.1) {
    copy_int /= 10;
    size_i++;
  }
  while (copy_fr > 0.1) {
    copy_fr /= 10;
    size_fr++;
  }
  s21_size_t size = size_fr + size_i;
  size++;
  if ((var_len < 0) || (flags.space) || (flags.plus)) size++;
  if ((flags.precision == 0) && (flags.is_precision)) size--;

  char* fract_str = malloc(sizeof(char) * (size + 1));

  s21_utoaf(flags, fract, integ, fract_str, buf, var_len, x);
  if (!flags.minus) {
    while ((s21_size_t)flags.width > size) {
      *str = ' ';
      str++;
      size++;
    }
  }
  for (s21_size_t i = 0; i < (s21_strlen(buf)); i++) {
    *str = buf[i];
    str++;
  }
  if (flags.minus) {
    while ((s21_size_t)flags.width > size) {
      *str = ' ';
      str++;
      size++;
    }
  }
  return str;
}

char* s21_utoaf(Flags flags, long int fract, long int integ, char* fract_str,
                char* buf, double var_len, int x) {
  int i = 0;
  long int copy_int = integ;
  long int copy_fr = fract;

  if ((flags.is_precision == 0) || (flags.precision > 0)) {
    do {
      fract_str[i++] = copy_fr % 10 + '0';
    } while ((copy_fr /= 10) > 0.1);
    while (i < x) {
      fract_str[i++] = '0';
    }
    fract_str[i++] = '.';
  }
  do {
    fract_str[i++] = copy_int % 10 + '0';
  } while ((copy_int /= 10) > 0.1);

  if (var_len < 0) {
    *buf = '-';
    buf++;
  } else if ((var_len > 0) && (flags.plus)) {
    *buf = '+';
    buf++;
  } else if ((var_len > 0) && (flags.space)) {
    *buf = ' ';
    buf++;
  }
  for (int j = i - 1; j >= 0; j--) {
    *buf = fract_str[j];
    buf++;
  }

  if (fract_str != NULL) free(fract_str);
  fract_str = NULL;
  return buf;
}

char* spec_char(const char c, Flags* flags, char* str) {
  if (flags->minus == 1) {
    ch2str(c, str);
  }
  str = space2str(flags->width, 1, flags->zero, str);

  if (flags->minus == 0) {
    ch2str(c, str);
  }
  str++;
  return str;
}

void ch2str(const char c, char* str) {
  *str = c;
  str++;
}
char* space2str(int width, int lenght, int zero_fill, char* str) {
  if ((width - lenght) < 0) {
    return str;
  }
  for (int i = 0; i < (width - lenght); i++) {
    if (zero_fill == 1) {
      ch2str('0', str);
    } else {
      ch2str(' ', str);
    }
    str++;
  }
  return str;
}

void reverse_str(char* str) {
  int len = s21_strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}
char* spec_string(char* s, Flags* flags, char* str) {
  char* ptr = str;
  if (s == NULL) {
    s21_strcpy(ptr, "(null)");
    ptr += sizeof("(null)");
  } else {
    int length = s21_strlen(s);

    if ((s21_size_t)flags->precision > s21_strlen(s)) {
      flags->precision = s21_strlen(s);
      length = s21_strlen(s);
    } else
      length = flags->precision;

    if (flags->minus == 1) {
      for (int i = 0; i < length; i++) {
        str[i] = s[i];
      }
      str = str + length;
      str = space2str(flags->width, length, flags->zero, str);
    } else {
      str = space2str(flags->width, length, flags->zero, str);
      for (int i = 0; i < length; i++) {
        str[i] = s[i];
      }
    }
    if (ptr) ptr = str;
  }
  return ptr;
}

char* spec_pointer(void* pointer, Flags* flags, char* str) {
  static char ar1[] = "0123456789abcdef";
  static char buffer[50];
  char* ptr;
  // int i = 0;
  if (pointer == NULL) {
    s21_strcpy(str, "(null)");
    str += sizeof("(null)");
  } else {
    unsigned long long num = (unsigned long long)pointer;
    // if (pointer == NULL)    //  flags->error = 1;
    // else    {
    ptr = &buffer[49];
    *ptr = '\0';
    do {
      *--ptr = ar1[num % 16];
      num /= 16;
    } while (num != 0);

    int pointer_len = (int)strlen(ptr);
    pointer_len += 2;
    // if (pointer_len < flags->width && flags->minus == 0) {
    // str = space2str(flags->width, pointer_len, flags->zero, str);
    //}
    // if (pointer_len < flags->width && flags->minus == 1) {
    // str = space2str(flags->width, pointer_len, flags->zero, str);
    //}
    // pointer_len += 2;
    *--ptr = 'x';
    *--ptr = '0';
    if (flags->minus == 1) {
      for (int i = 0; i < pointer_len; i++) {
        str[i] = ptr[i];
      }
      str = str + pointer_len;
      str = space2str(flags->width, pointer_len, flags->zero, str);
    } else {
      str = space2str(flags->width, pointer_len, flags->zero, str);
      for (int i = 0; i < pointer_len; i++) {
        str[i] = ptr[i];
      }
    }
  }

  /*while (ptr[i]) {
  str[i] = ptr[i];
  i++;
 } */
  // str = str + pointer_len;
  return str;
}

int get_len_num(uint32_t num) {
  int len = 0;

  if (num == 0) len = 1;
  /*else if (num < 0) {
          len++;
          num = -num;
  }*/
  while (num >= 1) {
    len++;
    num /= 10;
  }
  return len;
}
char* s21_utoa(unsigned int n, int len) {
  char* str = (char*)malloc((len + 1) * sizeof(char));
  // if (str == NULL)
  //	return NULL;

  str[len] = '\0';
  while (len--) {
    str[len] = (n % 10) + '0';
    n /= 10;
  }
  return str;
}
char* spec_unsign(uint64_t un, Flags* flags, char* str) {
  if (flags->length == 'l')
    un = (uint64_t)un;
  else if (flags->length == 'h')
    un = (uint16_t)un;
  else
    un = (uint32_t)un;

  int i = 0;
  int len = get_len_num(un);
  if (flags->space) len++;

  if (flags->precision) len = flags->precision;
  char* temp = s21_utoa(un, len);

  if (flags->space) temp[i] = ' ';

  int lenSp = (int)s21_strlen(temp);
  if (flags->width && !flags->minus) {
    str = space2str(flags->width, lenSp, flags->zero, str);
    for (int l = 0; l < lenSp; l++) str[l] = temp[l];
    str = str + lenSp;
  } else if (flags->width && flags->minus) {
    for (int j = 0; j < lenSp; j++) str[j] = temp[j];
    str += lenSp;
    for (int j = 0; j < flags->width - lenSp; j++) str[j] = ' ';
    str += (flags->width - lenSp);
  } else {
    for (int j = 0; j < lenSp; j++) str[j] = temp[j];
    str += lenSp;
  }
  char* temp2 = (char*)realloc(temp, (lenSp) * sizeof(char));
  str[lenSp] = '\0';

  if (temp2 != NULL) free(temp2);

  return str;
}
