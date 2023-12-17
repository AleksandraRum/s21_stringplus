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
s21_size_t s21_strcspn(const char* str, const char* sym)
{
	s21_size_t cnt = 0;
	for (s21_size_t i = 0; i < s21_strlen(str); i++)
	{
		if (strchr(sym, str[i]) == s21_NULL)
			cnt++;
		else
			break;
	}
	return cnt;
}
char* s21_strpbrk(const char* str, const char* sym)
{
	s21_size_t pos = 0, find =0;
	char* ptr = (char*)str;
	for (s21_size_t i = 0; i < s21_strlen(str); i++)
	{
		if (strchr(sym, ptr[i]) != s21_NULL)
		{	find = 1;
			break;
		}
		pos++;
	}
	return ( find == 1 ? ptr+pos : s21_NULL);
}
char *s21_strchr(const char *str, int symbol) {
    char *ptr = 0;
    while (*str != '\0') {
        if (*str == symbol) {
            ptr = (char*)str;
            break;
        }
        str++;
    }
    if (ptr == s21_NULL)
        return 0;
    else
        return ptr;
}
int s21_strncmp(const char *str1, const char *str2, s21_size_t num)
{ 
    int i = 0, diff = 0, res = 0; 
    while (num > 0 && (str1[i] != '\0' || str2[i] != '\0') && diff == 0) { 
        if (str1[i] != str2[i]) { 
            res = str1[i] - str2[i]; 
            break; 
        } else {
            diff++; 
        }
        i++;
        num--;
    } 
    return res; 
}
char* s21_strncpy( char * dest, const char * source, s21_size_t num )	
{
	s21_size_t it=0;
    while (source[it] != '\0' && num >0) {
        dest[it] = source[it];
		num--;
		it++;
    }
	for(;it<num;it++)
	    dest[it] = '\0';
    return dest;
}
char *s21_strstr(const char *dest, const char *source) {
  char *ptr = s21_NULL;
  while (*dest != '\0') {
      char *tmp = (char*)dest;
      char *tmp2 = (char*)source;
      while (*tmp == *tmp2) {
          tmp++;
          tmp2++;
          if (*tmp2 == '\0') {
              ptr = (char*)dest;
              break;
          }
      }
      dest++;
  }

  if (ptr == s21_NULL)
      return 0;
  else
      return ptr;
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

s21_size_t s21_strspn(const char* str, const char* sym)
{
	s21_size_t cnt = 0;
	for (s21_size_t i = 0; i < strlen(str); i++)
	{
		if (strchr(sym, str[i]) != s21_NULL)
			cnt++;
	}
	return cnt;
}

int* create_delim(const char* delim) {
    int* d = (int*)malloc(256 * sizeof(int));  // Increased the size of the array to account for all possible characters
    if (d == s21_NULL) {
        return s21_NULL;  // Return s21_NULL if memory could not be allocated
    }
    memset(d, 0, 256 * sizeof(int));  // Initialize the array with zeros

    s21_size_t i = 0;
    while (delim[i] != '\0') {
        d[(int)delim[i]] = 1;
        i++;
    }
    return d;
}

char* s21_strtok(char* str, const char* delim) {
    static char* last = s21_NULL;
    static char* strToFree = s21_NULL;

    int* deliDict = create_delim(delim);
    if (deliDict == s21_NULL) {  // We check whether it was possible to create a separator
        return s21_NULL;
    }
    if (str != s21_NULL) {
        if (strToFree != s21_NULL) {
            free(strToFree);
        }
        last = (char*)malloc(s21_strlen(str) + 1);
        if (last == s21_NULL) {
            free(deliDict);
            return s21_NULL;
        }
        strToFree = last;
        s21_strcpy(last, str);
    }

    while (deliDict[(int)*last] && *last != '\0') {
        last++;
    }
    str = last;
    if (*last == '\0') {
        free(deliDict);
        free(strToFree);
        return s21_NULL;
    }
    while (*last != '\0' && !deliDict[(int)*last]) {
        last++;
    }
    *last = '\0';
    last++;
    free(deliDict);
    return str;
}
>>>>>>> src/s21_string.c
