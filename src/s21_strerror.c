#include "s21_string.h"

char *s21_strerror(int errnum) {
    char *s_err;
    char* ERRORS[] = ERR_LIST;
    if (errnum >= 0 && errnum <= 133){
        s_err = (char*)ERRORS[errnum];
    }
    else {
        s_err = "Unknown error";
    }
    return s_err;
}