// 0. This is the lib_str.c
// 1. We have to include the lib_string.h file here because we use some value defined there.

#include "lib_string.h"

int ld_strlen()
{
	return _INA;
}

int jq_strlen(const char* str)
{
	int i;
	for (i = 0; i < STR_SIZE; i++)
		if (str[i] == '\0')
			return (i);
	return i;
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

int zs_strlen(const char *str)
{
	int len = 0;

//if ((str == NULL)||(*str == '\0'))
//	return 0;

	while (*str++)
		++len;
	return (len);
}

int _strlen()
{
	return _INA;
}

/**
 * 02. xx_strcat() is to attach str2 to str1, then return str1.
 */
char* ld_strcat(char *str, const char *substr)
{
	return _CPNA;
}

char* jq_strcat(char *str1, const char *str2)
{
	int len1 = jq_strlen(str1);
	int len2 = jq_strlen(str2);
	int i;
	if (len1 + len2 <= STR_SIZE)
	{
		for (i = 0; i < len2; i++)
			str1[len1 + i] = str2[i];
	}
	else
	{
		for (i = len1; i < STR_SIZE; i++)
			;
		str1[i] = str2[i - len1];
	}
	str1[len1 + i] = '\0';
	return (str1);
}

char* st_strcat(char *str, const char *substr)
{
	int len_str = st_strlen(str);
	int len_substr = st_strlen(substr);
	int cnt;
	for (cnt = 0; cnt <= len_substr; cnt++)
	{
		*(str + len_str + cnt) = *(substr + cnt);
	}
	return str;
}

char* zs_strcat(char *str, const char *substr)
{
	char *cp = str;
	while (*cp)
		++cp;  //Get end of str
	while (*cp++ = *substr++)
		; //copy substr to the end of str
	return (str);
}

char* _strcat(char *str, const char *substr)
{
	return _CPNA;
}

/**
 * 03. xx_strcmp() is to compare the str1 with str2.
 *     If str1!=str2, then return str1-str2; if str1==str2, then return 0;
 */
int ld_strcmp()
{
	return _INA;
}

int jq_strcmp(const char *str1, const char *str2)
{
	int i;
	for (i = 0; i < STR_SIZE; i++)
	{
		if (str1[i] == '\0')
			return (str1[i] - str2[i]);
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (str1[i] - str2[i]);
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

int zs_strcmp(const char *str, const char *substr)
{
	int ret = 0;
	while (!(ret = *str - *substr) && *substr)
		++str, ++substr;
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return (ret);
}

int _strcmp()
{
	return _INA;
}

/**
 * 04. xx_strcpy() is to copy str2 to str1. then return str1.
 */
char* ld_strcpy()
{
	return _CPNA;
}

char* jq_strcpy(char* str1, const char* str2)
{
	int i;
	int len2 = jq_strlen(str2);
	for (i = 0; i <= len2; i++)     //when i=len2, it copies '\0'
		str1[i] = str2[i];
	return str1;
}

char *st_strcpy(char *dest, const char *src)
{
	int i = 0;
	while ('\0' != *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return dest;
}

char* zs_strcpy(char *dest, const char *src)
{
	char*cp = dest;
	while (*cp++ = *src++)
		; // copy src to dest
	return (dest);
}

char* _strcpy()
{
	return _CPNA;
}

/**
 * 05. this is to insert a char or a substring to the string.
 */
char *st_strinsert(char *str, char *substr, int loc)
{
	char str_temp[STR_SIZE];
	st_strcpy(str_temp, str);
	int str_len = st_strlen(str_temp);
	int substr_len = st_strlen(substr);
	int i;
	for (i = loc; i < str_len; i++)
		str_temp[str_len + substr_len - i] = str_temp[str_len - i]; 
	for (i = 0; i < substr_len; i++)
		str_temp[loc + i] = substr[i];
	st_strcpy(str, str_temp);
	return str;
}

/**
 * 06. this is to delete all of the char or the substring from the string.
 */
char *st_strdel(char *str, char *substr);

/**
 * 07. this is to replace all of the char or the substring with another in the string.
 */
char *st_strrep(char *str, char *rep, char *origin)
{
	printf("str,rep,origin: %s,%s,%s\n", str, rep, origin);
	if (!st_strcmp(rep, origin))
	{
		int loc = 0;
		char str_temp[STR_SIZE];
		*(str_temp) = '\0';
		char* p = str;
		char *p1 = str;
		int i = 0, j = 0, k = 0;
		int str_temp_len;
		int str_len = st_strlen(str);
		int origin_len = st_strlen(origin);
		int rep_len = st_strlen(rep);
		while (-1 != (loc = st_strloc(p, origin)))
		{
			loc = st_strloc(p, origin);
			str_temp_len = st_strlen(str_temp);
			for (i = 0; i < loc; i++)
			{
				*(str_temp + str_temp_len + i) = *(p + i);
			}
			for (j = 0; j < rep_len; j++)
			{
				*(str_temp + str_temp_len + i + j) = *(rep + j);
			}
			*(str_temp + str_temp_len + i + j + 1) = '\0';
			p1 = str + loc + origin_len;
			st_strcat(str_temp, p1);
			p = p + loc + rep_len;
		}
		printf("str_temp : %s\n", str_temp);
		st_strcpy(str, str_temp);
		return str;
	}
}

/**
 * 08. this is to return the first location of char or the first char of substring.
 */
int st_strloc(char *str, char *substr)
{
	int len_str = 0;
	int len_substr = st_strlen(substr);
	int res = 0;
	while (('\0' != *(str + len_str)) && !res)
	{
		if (*(substr) == *(str + len_str))
		{
			res = 1;
			int i;
			for (i = 0; i < len_substr; i++)
			{
				if (*(str + len_str + i) != *(substr + i))
				{
					res = 0;
					break;
				}
			}
		}
		len_str++;
	}
	if (res)
	{
		return (len_str - 1);
	}
	else
	{
		return -1;
	}
}

