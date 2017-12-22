#include <stdio.h>

#include "float_x.h"

int main()
{
        union f_bits bits;
        bits.floating_number = 5.4;

        printf("[BEGIN]\t Floating number we work with is %f\n", bits.floating_number);
        printf("\t The sign bit is %d \t\t {%s}\n", bits.blueprint.sign, dec_to_bin(bits.blueprint.sign));
        printf("\t The mantissa bits are %d \t {%s}\n", bits.blueprint.mantissa, dec_to_bin(bits.blueprint.mantissa));
        printf("\t The exponent bits are %d \t {%s}\n", bits.blueprint.exponent, dec_to_bin(bits.blueprint.exponent));

        /*
         * Change the negative number to a posive one.
         * Here is the hacking part.
         */ 

        bits.blueprint.sign = 0;
        printf("[END]\t After hacking, the floating number is %f\n", bits.floating_number);
	
	float f = -16.5;
	printf("Sign is %c\n", get_sign(&f));	

	_set_sign(&f, 0);

	printf("f is %f\n", f);	
        return 0;
}  
