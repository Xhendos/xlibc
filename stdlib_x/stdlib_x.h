#ifndef	_STDLIB_X_H
#define	_STDLIB_X_H

#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1

typedef struct
{
	int quot;		/* Quotient */
	int rem;		/* Remainder */
} _div_t;

int _atoi(const char *nptr);

int _abs(int j);

_div_t div(int numer, int denom);

#endif	/* _STDLIB_X_H */
