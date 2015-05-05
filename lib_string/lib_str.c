// 01. This is the lib_str.c
#include "lib_string.h"

int ld_strlen()
{
	return -1;
}

int jq_strlen()
{
	return -1;
}

int st_strlen(const char *str)
{
	int len = 0;
	while ('\0' != *(str + len))
	{
		len++;
	}
	return len;
}

int zs_strlen()
{
	return -1;
}

int _strlen()
{
	return -1;
}

/**
* 02. xx_strcat() is to attach str2 to str1, then return str1.
*/
char* ld_strcat(char *str, const char *substr)
{
	return NA;
}

char* jq_strcat(char *str, const char *substr)
{
	return NA;
}

char* st_strcat(char *str, const char *substr)
{
	int len_str = st_strlen(str);
	int len_substr = st_strlen(substr);
	int cnt;
	for(cnt=0;cnt<=len_substr;cnt++)
	{
		*(str + len_str + cnt) = *(substr + cnt);
	}
	return str;
}

char* zs_strcat(char *str, const char *substr)
{
	return NA;
}

char* _strcat(char *str, const char *substr)
{
	return NA;
}

/**
* 03. xx_strcmp() is to compare the str1 with str2.
*     If str1!=str2, then return str1-str2; if str1==str2, then return 0;
*/
int ld_strcmp()
{
	return -1;
}

int jq_strcmp()
{
	return -1;
}

int st_strcmp(const char *str, const char *substr)
{
	int res = 1;
	int cnt = 0;
	const char *str_temp = str;
	const char *substr_temp = substr;
	if (st_strlen(str_temp) != st_strlen(substr_temp))
	{
		res = 0;
	}
	else
	{
		while (*(str_temp + cnt))
		{
			if (*(str_temp + cnt) != *(substr_temp + cnt))
			{
				res = 0;
				break;
			}
			else
			{
				cnt++;
			}
		}
	}
	return res;
}

int zs_strcmp()
{
	return -1;
}

int _strcmp()
{
	return -1;
}

/**
* 04. xx_strcpy() is to copy str2 to str1. then return str1.
*/
char* ld_strcpy()
{
	return NA;
}

char* jq_strcpy()
{
	return NA;
}

char *st_strcpy(char *dest, const char *src)
{
int i = 0;
	while('\0' != *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return dest;
}

char* zs_strcpy()
{
	return NA;
}

char* _strcpy()
{
	return NA;
}

