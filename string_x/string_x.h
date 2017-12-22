#ifndef	_STRING_X_H
#define	_STRING_X_H

/* Defining */
#define	_NULL		((void *) 0)			/* This is how it is defined in stddef.h 
							 * (GNU/Linux 4.13.12-1) */

typedef	unsigned int	_size_t;			/* This is how it is defined in <sys/null.h> 
							 * (Minix 3.1.8) */

/* Function prototyping */
int _strcmp(const char *s1, const char *s2);

int _strncmp(const char *s1, const char *s2, _size_t n);

char *_strcpy(char *dest, const char *src);

char *_strncpy(char *dest, const char *src, _size_t n);

_size_t _strlen(const char *s);

char *_strcat(char *dest, const char *src);

void *_memchr(const void *s, int c, _size_t n);

void *_memset(void *s, int c, _size_t n);

_size_t _strspn(const char *s, const char *accept);

_size_t _strcspn(const char *s, const char *reject);

char *_strstr(const char *haystack, const char *needle);

char *_strchr(const char *s, int c);

char *_strrchr(const char *s, int c);

char *_strpbrk(const char *s, const char *accept);

void *_memcpy(void *dest, const void *src, _size_t n);	/* Maybe not implemented well */

/* Extra functions which are not in the string.h */

char *_strrev(char *s);					/* Reverse a string */

_size_t strwords(const char *s)				/* Count the amount of words */

#endif
