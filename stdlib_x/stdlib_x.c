#include "stdlib_x.h"					/* Contains div_t defenition */

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


/* 
 * The most common way is to  represent a negative number is two's complement and add 1.
 * Number| Two's complement			   |
 * ======|=========================================|
 *  6  	 | 0000 0000 0000 0000 0000 0000 0000 0110 |
 *  -6	 | 1111 1111 1111 1111 1111 1111 1111 1010 |
 *	  
 * The maximal integer is 2^(31) (in bin 01111111111111111111111111111111 and in hex 7FFFFFFF).
 * The most significant bit is reserved and can be used to determine if a number is positive or negative.
 * 
 */
int _abs(int j)
{
	if(!(j >> 31)) return j;			/* If the msb is a 0 (positive number) return it */
	return (~j) + 1;				/* If the msb is a 1 execute a two's complement on the number and return it */
}

/*
 * Imagine we have 26/4. We want to return a structure with quotient of 6 and a remainder of 2 (((6 * 4) + 2) is 26)
 * Let's try for each value (starting at 0) to multiply with the denominator and see if the result is less than the numerator
 * 1] 4 * 0 = 0		(Less than 26)
 * 2] 4 * 1 = 4		(Less than 26)
 * 3] 4 * 2 = 8		(Less than 26)
 * 4] 4 * 3 = 8		(Less than 26)  
 * 5] 4 * 4 = 16        (Less than 26)  
 * 6] 4 * 5 = 20        (Less than 26)  
 * 7] 4 * 6 = 24        (Less than 26)  
 * 8] 4 * 7 = 28	(Greater than 26. Stop loop)
 *
 * Finally we check if it's equal greater than the numerator or equal.
 * If it's greater we substract 1 from the quotient and get the final remainder.
 */
_div_t _div(int numer, int denom)
{
	_div_t ret;
	int _quot;

	for(_quot = 0; (denom * _quot) < numer; _quot++);
	
	if((_quot * denom) > numer)
	{
		ret.quot = --_quot;
		ret.rem = (numer - (_quot * denom));
	} else
	{
		ret.quot = _quot;
		ret.rem = 0;		
	}
	
	return ret;
}

