int _isalnum(int c)
{
	if((c >= '0' && c <= '9') ||
	  ((c >= 'a' && c <= 'z') ||
	  ((c >= 'A' && c <= 'Z')))) 
	return c;
	
	return 0;
}

int _isalpha(int c)
{
	if((c >= 'a' && c <= 'z') ||
	  (c >= 'A' && c <= 'Z'))
	return c;

	return 0;
}

int _iscntrl(int c)
{
	if((c >= 0 && c <= 31) || c == 127)
	return c;

	return 0;
}

int _isidigt(int c)
{
	if(c >= '0' && c <= '9')
	return c;

	return 0;
}

int _ispunct(int c)
{
	if((c >= 33 && c <= 47) ||
	  (c >= 58 && c <= 64) ||
	  (c >= 91 && c <= 96) ||
	  (c >= 123 && c <= 126))
	return c;

	return 0;
}

int _isgraph(int c)
{
	if(_isalnum(c) || _ispunct(c))
	return c;

	return 0;
}

int _islower(int c)
{
	if(c >= 'a' && c <= 'z')
	return c;

	return 0;
}

/* tab, newline, vertical tab, form feed, carriage return and space */
int _isspace(int c)
{
	if((c >= 9 && c <= 13) || c == 32)
	return c;

	return 0;
}

int _isprint(int c)
{
	if(_isalnum(c) || _ispunct(c) || _isspace(c))
	return c;

	return 0;
}

int _isupper(int c)
{
	if(c >= 'A' && c <= 'Z')
	return c;

	return 0;
}

int _isxdigit(int c)
{
	if((c >= '0' && c <= '9') ||
	  ( c >= 'a' && c <= 'f') ||
	  ( c >= 'A' && c <= 'F'))
	return c;

	return 0;
}


int _toupper(int c)
{
	if(_islower(c)) return c - 32;
	
	return c;
}

int _tolower(int c)
{
	if(_isupper(c)) return c + 32;

	return c;
}
