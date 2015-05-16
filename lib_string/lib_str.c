// 0. This is the lib_str.c
// 1. We have to include the lib_string.h file here because we use some value defined there.

#include "lib_string.h"
#include "stdio.h"

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
	//jhkh
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
	while (! (ret = *str - *substr) && *substr)
		++str, ++substr;
	if(ret < 0)
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

//JQ: if the final length of the string is longer than STR_SIZE, the excess part will be discarded.
char* jq_strinsert(char* str, const char* substr, const int index)
{
int len=jq_strlen(str);
if(index>len) return(str);   //the index is outside the string
int slen=jq_strlen(substr);
//printf("The length of str is: %d; & the length of substr is: %d\n", len, slen);
int i;
if((len+slen)<STR_SIZE)   //enough space for str + substr
	{
	for(i=0;i<=len-index;i++)
		{
		str[len+slen-i]=str[len-i];  //move str behind index part back
//		printf ("during move: when i=%d, we got: %s\n",i,str);
		}
	for(i=0;i<slen;i++)
		str[index+i]=substr[i];  //insert substr
	}

else if((index+slen)>=(STR_SIZE-1)) //not only part of str, but also part of substr will be discarded.
	{
	str[STR_SIZE-1]='\0';   //to complete the new string for return
	for(i=0;i<STR_SIZE-index-1;i++)   //can only insert part of substr
		str[index+i]=substr[i];
	}

else				// substr can be insert, but part of str will be discarded.
	{
	str[STR_SIZE-1]='\0';   //to complete the new string for return

//for(i=len;i<STR_SIZE-1;i++) str[i]='z';
//printf ("33333333 ---, str1=%s, & str2=%s \n", str, substr);
	for(i=0;i<=(STR_SIZE-2)-(index+slen);i++)
	// (STR_SIZE-2) means: 1 for the last '\0', another 1 for array starts from 0.
		{
		str[(STR_SIZE-2)-i]=str[(STR_SIZE-2)-slen-i]; //move part of str back for substr
//printf ("during move: when i=%d, we got: %s\n",i,str);
		}
	for(i=0;i<slen;i++)
		{
		str[index+i]=substr[i];  //insert substr
//printf ("during insert: as i=%d, we got: %s\n",i,str);
		}
	}
return (str);
}

/**
 * 06. this is to delete all of the char or the substring from the string.
 */
char *st_strdel(char *str, char *substr)
{
	char *temp = "";
	return st_strrep(str, temp, substr);
}

char* jq_strdel(char* str, const char* substr)
{
int loc=-1,i;
int len=jq_strlen(str);
int slen=jq_strlen(substr);
while((loc=jq_strloc(str,substr,0))>=0)
	{
	for(i=0;i<len-loc-slen;i++)
		str[loc+i]=str[loc+slen+i]; // to remove substr part from str
	str[loc+i]='\0';  //set the end of the new string
	}
return (str);
}


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
		int i = 0, j = 0;
		int str_temp_len;
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
			if (0 < rep_len)
			{
				for (j = 0; j < rep_len; j++)
				{
					*(str_temp + str_temp_len + i + j) = *(rep + j);
				}
			}
			*(str_temp + str_temp_len + i + j + 1) = '\0';
			p1 = str + loc + origin_len;
			st_strcat(str_temp, p1);
			p = p + loc + origin_len;
		}
		printf("str_temp : %s\n", str_temp);
		st_strcpy(str, str_temp);
		return str;
	}
}


// JQ: str is the string we work on, rep contains the replacing info,
//     while origin is the info to be replaced.
// Note: the excess part of STR_SIZE will be discarded.
char* jq_strreplace(char* str, const char* rep, const char* origin)
{
int bp=0;  //set the begin point for loc
int loc = jq_strloc(str,origin,bp);
int rlen=jq_strlen(rep);   //length will not change
int olen=jq_strlen(origin);   //length will not change
int i;
//printf("in function(), str=%s, rep=%s, origin=%s; & the 1st loc=%d\n",str,rep,origin,loc);
while (loc!=-1)
	{
	int len=jq_strlen(str);  //the length of str changes every time after replacement
//printf("When str=%s, loc=%d:\n",str,loc);
	for(i=0;i<len-loc-olen;i++)  // to remove origin part from str
		{
		str[loc+i]=str[loc+olen+i];
//printf("i=%d, str=%s\n",i,str);
		}
	str[loc+i]='\0';  //set the end of the new string
//printf("after remove this origin part, str=%s\n",str);
	str=jq_strinsert(str, rep, loc);  //then, insert rep part to str
//printf("after insert this replace part, str=%s\n",str);
	bp=loc+rlen;    //set the new begin point after this replacement
	loc=jq_strloc(str, origin, bp);
	}
return (str);
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

//JQ: return -1 if we can not find the location.
//JQ: return the first substr location scanning from a given begin point
int jq_strloc(const char* str, const char* substr, const int bp) //bp: begin point
{
int r;   //for return
int c;   //for count
int m=0;   //for mark
int i= jq_strlen(str);
int j= jq_strlen(substr);
//printf("str=%s, substr=%s; and len-str=%d, len-substr=%d\n",str,substr,i,j);
if(i<j) return(-1);
for(r=bp;r<=(i-j);r++)
	{
	m=0;
	for(c=0;c<j;c++)
		if(str[r+c]!=substr[c])
		{
		   m=1; break;
		}
	if(m==0) return(r);
	}
return (-1);
}
