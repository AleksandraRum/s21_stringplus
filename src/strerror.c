#include "s21_string.h"
#include "s21_sprintf.h"

char *s21_strerror(int errnum) {
    char* s_err;
    char* ERRORS[] = ERR_LIST;
    if (errnum >= 0 && errnum <= 133){
        s_err = (char*)ERRORS[errnum];
    }
    else {
        static char buffer[80];
        s21_sprintf(buffer, "Unknown error: %d", errnum);
        s_err = buffer;
    }
    return s_err;
}