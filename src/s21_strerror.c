#include "s21_sprintf.h"
#include "s21_string.h"

char *s21_strerror(int errnum) {
  char *ERRORS[] = ERR_LIST;
  char *s_err;
  if (errnum >= 0 && errnum <= N) {
    s_err = (char *)ERRORS[errnum];
  } else {
    static char buffer[80];
    if (std == 0) {
      s21_sprintf(buffer, "Unknown error %d", errnum);
      s_err = buffer;
    } else if (std == 1) {
      s21_sprintf(buffer, "Unknown error: %d", errnum);
      s_err = buffer;
    }
  }
  return s_err;
}
