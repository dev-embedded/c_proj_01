// 0. This is the str_test.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib_string.h"

int str_test()
{
printf("Now, we are going to test the string lib functions created by ourselves.\n");
printf("We have 4 functions: strlen, strcmp, strcat, strcpy.\n");
printf("There are two string, string 1 is: \"0123456789\", string 2 is\"aaa\"\n");

char str1[20], str2[10];
strcpy(str1,S1); strcpy(str2, S2);
printf("Test Start ... ...\n");

printf("1. test the _strlen() of string 1:\n");
printf("LINGdong's answer=%2d; JQ's answer=%2d; ST's answer=%2d; ZS's answer=%2d.\n",\
		ld_strlen(str1), jq_strlen(str1), st_strlen(str1), zs_strlen(str1));

printf("\n2. test the _strcmp() to compare string 1 with string 2:\n");
printf("LINGdong's answer=%2d; JQ's answer=%2d; ST's answer=%2d; ZS's answer=%2d.\n",\
		ld_strcmp(str1,str2), jq_strcmp(str1,str2), st_strcmp(str1,str2), zs_strcmp(str1,str2));

printf("\n3. test the _strcat() to attach string 2 after string 1:\n");
printf("LINGdong's answer=%s\n", ld_strcat(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
printf("JQ's answer=%s\n", jq_strcat(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
printf("ST's answer=%s\n", st_strcat(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
printf("ZS's answer=%s\n", zs_strcat(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
/*
printf("\n4. test the _strcpy() to copy string 2 to string 1:\n");
printf("LINGdong's answer=%s\n", ld_strcpy(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
printf("JQ's answer=%s\n", jq_strcpy(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
pringf("ST's answer=%s\n", st_strcpy(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
printf("ZS's answer=%s\n", zs_strcpy(str1,str2));
strcpy(str1,S1); strcpy(str2, S2);
*/
return 0;
}
