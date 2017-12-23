#include <stdlib.h>
#include <stdio.h>

char is_digit(const char c)
{
	if(c >= '0' && c <= '9') return '1';
	return '\0';
}


/*
 * Imagine we have a pointer to "125\0"
 * Let's walk through each loop cycle to see what happens:
 * 1] (0 * 10) + '1' - '0' 	The result is 1
 * 2] (1 * 10) + '2' - '0'	The result is 12
 * 3] (12 * 10) + '5' - '0'	The result is 125
 *
 * Once we meet the null terminator we won't loop for another cycle. 
 * This value is muliplied to convert the value to a negative number (if needed) 
 */
int _atoi(const char *nptr)
{
	int sign = 1;					/* The default multiplier is 1 (positive value) */
	int ret = 0;					/* Return value that contains the whole the number that nptr points to */
	
	while(*nptr == 9 || *nptr == 32) nptr++;	/* While we see a tab or a space, go to the next character */
	for( ; *nptr == '-'; nptr++) sign = -1;		/* If the character is ascii 49 (negative sign), our multiplier is negative */

	for( ; is_digit(*nptr) && *nptr; nptr++)	/* While the next character is a digit AND not a null terminator */
		ret = (ret * 10) + *nptr - '0';		

	return (ret * sign);				/* Return a positive OR a negative number, depends on int sign */
}

