#ifndef	_FLOAT_X_H 
#define	_FLOAT_X_H


/* Provided by Pantsu in "The Coding Den" Discord channel */
/*
 * This union data format takes a float number and store the correct bits in the bitfields.
 * NOTE: This are 32 bits (4bytes) floating numbers on a little endian system.
 */
union f_bits
{
	struct
	{
		unsigned int mantissa:23;			
		unsigned int exponent:8;			/* Real exponent is exponent - 127 */
		unsigned int sign:1;				/* 0 represents a positive number. 1 represents a negative number */
	} blueprint;
	
	float floating_number;					
};

/* Function prototyping */

/****************************************************************************************************************
 *                                                                                                              *       
 * dec_to_bin(int decimal)                                                                                      *       
 *                                                                                                              *
 * This is the entry point from another subroutine that wants to convert a decimal number into a binary one     *
 * It allocates the memory and calls the real subroutine that converts the decimal number                       *
 *                                                                                                              *
 ****************************************************************************************************************/
char* dec_to_bin(int decimal);


/************************************************************************************************************************
 *                                                                                                                      *
 * real_dec_to_bin(int decimal, char* binary)                                                                           *
 *                                                                                                                      *
 * Does all the real arithmetic which results in a reversed binary presentation of a decimal number                     *
 * Does not return anything, so we try to simulate a 'pass by reference' with the character pointer as argument         *
 *                                                                                                                      *
 ************************************************************************************************************************/
void real_dec_to_bin(int decimal, char* binary);

/****************************************************************************************
 *                                                                                      *
 * reverse(char* binary)                                                                *
 *                                                                                      *
 * reverse the given character array                                                    *
 * The only character that will not be swapped (100%) is the null terminator            *
 *                                                                                      *
 ****************************************************************************************/
void reverse(char* binary);

/****************************************************************************************
 *                                                                                      *
 * get_length(char* string)                                                             *
 *                                                                                      *
 * Takes a string pointer and returns the amount of bytes that are reserved             *
 * The null terminator is not counted                                                   *
 *                                                                                      *
 ****************************************************************************************/
int get_length(char* string);


/********************************************************************************
 *                                                                              *
 * set_sign(const float *f, int value)						*
 *                                                                              *
 * Takes a floating pointer and value as argument                               *
 * Set the floating number in a union and modify the sign bit                   *
 * Returns the new floating number                                              *
 *                                                                              *
 ********************************************************************************/
float set_sign(const float *f, int value);


/********************************************************************************
 *                                                                              *
 * _set_sign(const float *f, int value)						*
 *                                                                              *
 * Takes a floating pointer and value as argument                               *
 * Set the floating number in a union and modify the sign bit                   *
 * The floating number f is changed (pass by reference)				*
 *                                                                              *
 ********************************************************************************/ 
void _set_sign(float *f, int value);

/********************************************************************************
 *                                                                              *
 * get_sign(float* f)		                                                *
 *                                                                              *
 * Takes a floating pointer as argument and set this in the union		*
 * Returns the sign bit as a character                                          *
 *                                                                              *
 ********************************************************************************/
char get_sign(const float* f);


/* new  */
void manipulate(float *f, int value);

#endif
