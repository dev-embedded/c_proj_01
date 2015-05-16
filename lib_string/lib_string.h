// 0. This is the lib_string.h
// 1. For the constant values, NOT like functions, we can:
//    1-a.	use #define CNAME value to define them in a ".h" file; then include this .h file
//		  	in every .c file which will use these definitions.
//	  1-b.	define the value in one .c file; and declare it with "extern" in a .h file; then
//			include that .h file in every .c file which will use these definitions.

#ifndef LIB_STRING_H_
#define LIB_STRING_H_

#define STR_SIZE 18   //the max length of a string
#define _CPNA "Not Available!" 	//function NOT Ready for char* ()
#define _INA -999				//function NOT Ready for int ()
#define _S1 "0123456789"
#define _S2 "aaa"
#define _S3 "456"

//The following declaration works with definition in str_test.c, but now, we try the #define, see up.
//extern char *_S1, *_S2, *_CPNA;
//extern int _INA;

/**
* 00. to test the string function.
*     This function locations separately in str_test.c
*     The others functions followed stored in a file named lib_str.c
*/
int str_test();

/**
* 01. xx_strlen() is to get the length of a string, '\0' is not included in.
*     xx is the developer's name for short: ld for Ling Dong,
*     st for Sun Tao, zs for Zhou Song, and jq for Juequ
*     _strlen is the original lib function for comparation.
*/
int ld_strlen();
int jq_strlen(const char* str);
int st_strlen(const char *str);
int zs_strlen();
int _strlen();

/**
* 02. xx_strcat() is to attach str2 to str1, then return str1.
*/
char* ld_strcat();
char* jq_strcat(char *str1, const char *str2);
char* st_strcat(char *str, const char *substr);
char* zs_strcat();
char* _strcat();

/**
* 03. xx_strcmp() is to compare the str1 with str2.
*     If str1!=str2, then return str1-str2; if str1==str2, then return 0;
*/
int ld_strcmp();
int jq_strcmp(const char *str1, const char *str2);
int st_strcmp(const char *str, const char *substr);
int zs_strcmp();
int _strcmp();

/**
* 04. xx_strcpy() is to copy str2 to str1. then return str1.
*/
char* ld_strcpy();
char* jq_strcpy(char* str1, const char* str2);
char *st_strcpy(char *dest, const char *src);
char* zs_strcpy();
char* _strcpy();

/**
* 05. this is to insert a char or a substring to the string.
*/
char *st_strinsert(char *str0, char *substr, int loc);
char* jq_strinsert(char* str, const char* substr, const int index);

/**
* 06. this is to delete all of the char or the substring from the string.
*/
char *st_strdel(char *str, char *substr);
char* jq_strdel(char* str, const char* substr);

/**
* 07. this is to replace all of the char or the substring with another in the string.
*/
char *st_strrep(char *str, char *rep, char *origin);
char* jq_strreplace(char* str, const char* rep, const char* origin);

/**
* 08. this is to return the first location of char or the first char of substring.
*/
int st_strloc(char *str, char *substr);
//JQ: return the first substr location scanning from a given begin point
int jq_strloc(const char* str, const char* substr, const int bp);  //bp: begin point.

#endif  /* LIB_STRING_H_ */
