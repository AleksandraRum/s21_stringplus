#include "s21_string.h"

#include <stdio.h>
#include <string.h>


int main() {
    /*char src[] = "HELLO, World!";
    char dst[20] = "";
    if (strcmp(memcpy(dst, src, 6), s21_memcpy(dst, src, 6)) == 0) printf ("OK\n");
    else printf("Not OK\n");

    char src1[] = "Hello, World!";
    char dst1[] = "dfgshayjdkd";
    if (strcmp(memcpy(dst1, src1, 6), s21_memcpy(dst1, src1, 6)) == 0) printf ("OK\n");
    else printf("Not OK\n");

    char src2[] = "Hello, World!";
    char dst2[10] = "";
    if (strcmp(memcpy(dst2, src2, 6), s21_memcpy(dst2, src2, 6)) == 0) printf ("OK\n");
    else printf("Not OK\n");

    char l = 'l';
    char *ptr1;
    ptr1 = s21_memchr(src, l, 6);
    char *ptr2;
    ptr2 = memchr(src, l, 6);
    if ((ptr1 - src) == (ptr2 - src)) printf ("OK\n");
    else printf("Not OK\n");
   
    char d = 'd';
    char *ptr3;
    ptr3 = s21_memchr(src, d, 6);
    char *ptr4;
    ptr4 = memchr(src, d, 6);
    if ((ptr3 - src) == (ptr4 - src)) printf ("OK\n");
    else printf("Not OK\n");

    
    char src3[] = "Hello, world!";
    if (memcmp(src, src1, 6) == s21_memcmp(src, src1, 6)) printf ("OKcmp\n");
    else printf("Not OK\n");
    if (memcmp(src2, src1, 6) == s21_memcmp(src2, src1, 6)) printf ("OKcmp\n");
    else printf("Not OK\n");
    if (memcmp(src2, src3, 5) == s21_memcmp(src2, src3, 5)) printf ("OKcmp\n");
    else printf("Not OK\n");

    if (strcmp(memset(dst2, l, 6), s21_memset(dst2, l, 6)) == 0) printf ("OKset\n");
    else printf("Not OK\n");
    if (strcmp(memset(src, l, 6), s21_memset(src, l, 6)) == 0) printf ("OKset\n");
    else printf("Not OK\n");*/


    char str[20] = "";
    char str1[20] = "";
    /*printf("%d\n", sprintf(str, "Hello %+d", 148));
    //s21_sprintf(str1, "Hello % -6d", 148);
    printf("%d\n", s21_sprintf(str1, "Hello %+d", 148));
    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%d\n", sprintf(str, "Hello %+5d", -1465));
    printf("%d\n", s21_sprintf(str1, "Hello %+5d", -1456));
    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%d\n", sprintf(str, "Hello %-3.5d", 18));
    printf("%d\n", s21_sprintf(str1, "Hello %-3.5d", 18));
    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%d\n", sprintf(str, "Hello %d", -148148));
    printf("%d\n", s21_sprintf(str1, "Hello %d", -148148));
    printf("%s\n", str);
    printf("%s\n", str1);*/
    printf("%d\n", sprintf(str, "Hello %10d", 10123));
    printf("%d\n", s21_sprintf(str1, "Hello %10d", 10123));
    printf("%s\n", str);
    printf("%s\n", str1);
    
return 0;
}

