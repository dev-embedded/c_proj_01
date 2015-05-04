// 0. This is the lib_string.h

#ifndef LIB_STRING_H_
#define LIB_STRING_H_

#define STR_SIZE 80   //the max length of a string

const char *S1="0123456789";
const char *S2="aaa";

/**
* 00. to test the string function.
*     This function locations separately in str_test.c
*     The others functions followed stored in a file named lib_str.c
*/
//int str_test();

/**
* 01. xx_strlen() is to get the length of a string, '\0' is not included in.
*     xx is the developer's name for short: ld for Ling Dong,
*     st for Sun Tao, zs for Zhou Song, and jq for Juequ
*     _strlen is the original lib function for comparation.
*/
int ld_strlen();
int jq_strlen();
int st_strlen(const char *str);
int zs_strlen();
int _strlen();

/**
* 02. xx_strcat() is to attach str2 to str1, then return str1.
*/
char* ld_strcat();
char* jq_strcat();
char* st_strcat();
char* zs_strcat();
char* _strcat();

/**
* 03. xx_strcmp() is to compare the str1 with str2.
*     If str1!=str2, then return str1-str2; if str1==str2, then return 0;
*/
int ld_strcmp();
int jq_strcmp();
int st_strcmp();
int zs_strcmp();
int _strcmp();

/**
* 04. xx_strcpy() is to copy str2 to str1. then return str1.
*/
int ld_strcpy();
int jq_strcpy();
int st_strcpy();
int zs_strcpy();
int _strcpy();


#endif  /* LIB_STRING_H_ */
