#include <stdio.h>
#include <stdlib.h>

#include "float_x.h"


/****************************************************************************************************************
 *														*	
 * dec_to_bin(int decimal)											*	
 *														*
 * This is the entry point from another subroutine that wants to convert a decimal number into a binary one	*
 * It allocates the memory and calls the real subroutine that converts the decimal number			*
 *														*
 ****************************************************************************************************************/
char* dec_to_bin(int decimal) 
{
	char* binary = malloc(sizeof(char) * 1024);
	real_dec_to_bin(decimal, binary);
	
	reverse(binary);

	return binary;

}

/************************************************************************************************************************
 *															*
 * real_dec_to_bin(int decimal, char* binary)										*
 *															*
 * Does all the real arithmetic which results in a reversed binary presentation of a decimal number			*
 * Does not return anything, so we try to simulate a 'pass by reference' with the character pointer as argument		*
 *															*
 ************************************************************************************************************************/
void real_dec_to_bin(int decimal, char* binary)
{
	int remainder;

	while(decimal != 0)
	{
		remainder = decimal % 2;
		decimal = decimal / 2;
		*binary = (remainder + 48); 	/* 0 (int) is 0000 0000 in ascii representation */
						/* If we add 48 to the integer we get the '0' or '1' which are the characters for 0 and 1 */
		binary++;
	}
	*binary = '\0';
}


/****************************************************************************************
 * 											*
 * reverse(char* binary)								*
 * 											*
 * reverse the given character array							*
 * The only character that will not be swapped (garantued) is the null terminator	*
 *											*
 ****************************************************************************************/
void reverse(char* binary)
{
	char temporarry;
	int length = get_length(binary);
	
	char* last_index = binary;
	for(int dummy = 0; dummy < (length - 1); dummy++)
	{
		last_index++;
	}

	for(int i = 0; i < (length / 2); i++)
	{
		temporarry = *binary;
		*binary = *last_index;
		*last_index = temporarry;

		binary++;
		last_index--;
	}
}


/****************************************************************************************
 *											*
 * get_length(char* string)								*
 * 											*
 * Takes a string pointer and returns the amount of bytes that are reserved		*
 * The null terminator is not counted							*
 *											*
 ****************************************************************************************/
int get_length(char* string)
{
	int length;
	for(length = 0; *string != '\0'; length++) string++;

	return length;
}

/********************************************************************************
 *										*
 * set_sign(const float* f, int value)						*
 *										*
 * Takes a floating pointer and value as argument				*
 * Set the floating number in a union and modify the sign bit			*
 * Returns the new floating number						*
 *										*
 ********************************************************************************/
float set_sign(const float *f, int value)
{
	union f_bits bits;
	bits.floating_number = *f;
	(!value) ? (bits.blueprint.sign = 0) : (bits.blueprint.sign = 1);
	return bits.floating_number;
}

/********************************************************************************
 *                                                                              *
 * _set_sign(float* f, int value)                                    		*
 *                                                                              *
 * Takes a floating pointer and value as argument                               *
 * Set the floating number in a union and modify the sign bit                   *
 * Set float f to the new representation (pass by reference) 			*
 *                                                                              *
 ********************************************************************************/
void _set_sign(float *f, int value)
{
	union f_bits bits;
	bits.floating_number = *f;
	(!value) ? (bits.blueprint.sign = 0) : (bits.blueprint.sign = 1);
	*f = bits.floating_number;	
}

/********************************************************************************
 *                                                                              *
 * get_sign(float* f)                                                           *
 *                                                                              *
 * Takes a floating pointer as argument and set this in the union               *
 * Returns the sign bit as a character                                          *
 *                                                                              *
 ********************************************************************************/
char get_sign(const float* f)
{
	union f_bits bits;
	bits.floating_number = *f;
	return (bits.blueprint.sign + 48);
	/* Add 48 to the sign bit because the ascii character for 0 is 48 and the ascii character for 1 is 49 */
}


