#include "string_x.h"

int _strcmp(const char *s1, const char *s2)
{
	while(*s1 != '\0')
	{
		if(*s1 == *s2)
		{
			s1++;
			s2++;
		} else
		{
			return (*s1 > *s2) ? 1 : -1;
		}
	}		
	return *s1 - *s2;
}


int _strncmp(const char *s1, const char *s2, _size_t n)
{
	for(_size_t c = 0; c < n; c++, s1++, s2++)
	{
		if( !(*s1) || !(*s2) ) return (*s1 - *s2);
		if(*s1 != *s2) return (*s1 - *s2);
	}

	return (*s1 - *s2);
}

char *_strcpy(char *dest, const char *src)
{
	char *ret = dest;

	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	
	return ret;
}

char *_strncpy(char *dest, const char *src, _size_t n)
{
	_size_t i;

	for(i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	for( ; i < n; i++)
	{
		dest[i] = '\0';
	}

	return dest;
}

_size_t _strlen(const char *s)
{
	_size_t c = 0;
	/* while(*s++ != '\0') c++;*/
	
	while(*s++) c++;
	return c;
}

char *_strcat(char *dest, const char *src)
{
	char *ret = dest;
	/*	
	do
	{
		dest++;
	} while(*dest != '\0');
	*/
	while( (*dest) != '\0' ) dest++;

	for( ;*src != '\0'; src++, dest++)
	{
		*dest = *src;
	}
	*dest = '\0';

	return ret;
}

/* Inspired by https://github.com/akshaykemekar/string.h/blob/master/string.c */
void *_memset(void *s, int c, _size_t n)
{
	char *p = s;
	while(n--)
	{
		*p++ = c;
	}

	return s;	
}

/* Thanks to Jeroen Bol for the fine tuning (const char and void pointer) */
void *_memchr(const void *s, int c, _size_t n)
{
	const char *ret = s;

	for(_size_t i = 0; i < n; i++)
	{
		if(*ret == c) return (void*) ret;
		ret++;
	}

	return _NULL;
}

_size_t _strspn(const char *s, const char *accept)
{
	_size_t c = 0;

	for( ; *s != '\0'; s++)
	{
		_size_t lc;
		for(lc = 0; accept[lc] != '\0' && *s != accept[lc]; lc++);

		if(accept[lc] == '\0') break;

		c++;
	}

	return c;
}

_size_t _strcspn(const char *s, const char *reject)
{
	_size_t c = 0;

	for( ; *s != '\0'; s++)
	{
		_size_t lc;
		for(lc = 0; reject[lc] != '\0' && *s != reject[lc]; lc++);
		
		if(reject[lc] != '\0') break;

		c++;
	}
	return c;
}

/* Uses the function _strncmp() and _strlen() */
char *_strstr(const char *haystack, const char *needle)
{
	while(*haystack != '\0')
	{
		if(!_strncmp(haystack, needle, _strlen(needle))) return (char *) haystack;
		haystack++;
	}	

	return _NULL;
}

char *_strchr(const char *s, int c)
{
	/*
	while(*s != '\0')
	{
		if(*s == c)
		{
			return (char *) s;
		}
		s++;
	}		
	*/

	for( ; *s != '\0'; s++)
	{
		if(*s == c) return (char *) s;
	}

	return _NULL;
}

char *_strrchr(const char *s, int c)
{
	char *ret = _NULL;
	
	for( ; *s != '\0'; s++)
	{
		if(*s == c) ret = (char *) s;
	}

	return ret;
}

char *_strpbrk(const char *s, const char *accept)
{
	for( ; *s != '\0'; s++)
	{
		for(_size_t c = 0; accept[c] != '\0'; c++)
		{
			if(*s == accept[c]) return (char *) s;
		}
	}

	return _NULL;
}

void *_memcpy(void *dest, const void *src, _size_t n)
{
	void *ret = dest;

	for(_size_t c = 0; c < n; c++, dest++, (void *) src++)
	{
		*(char *) dest = *(char *) src;
	}
	
	return ret;
}

/* Extra functions which are not in the string.h */

char *_strrev(char *s)
{
	char *ret = s;
	_size_t lngth = _strlen(s);
	
	char *rghtbt = s + (lngth - 1);

	for( ; s < rghtbt; s++, rghtbt--)
	{
		char tmp = *s;
		*s = *rghtbt;
		*rghtbt = tmp;
	}

	return ret;
}

_size_t strwords(const char *s)
{
	_size_t = 0;
		

}
