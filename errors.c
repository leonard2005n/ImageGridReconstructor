//315CA-Neacsa Leonard
#include <stdio.h>
#include "error.h"

//Function that prints the error for invalid image
void error_img_type(void)
{
	printf("Eroare: trebuie sa fie P3\n");
}

//Function that prints the error for invalid pixel value
void error_pixel_invalid(void)
{
	printf("Eroare: valoare pixel necorespunzatoare\n");
}

//Function that prints the error for erorr of reading pixels
void error_pixel_scan(void)
{
	printf("Eroare: eroare citire pixeli\n");
}

//Function that prints the error for reading a invalid pixel value
void error_pixel_val(void)
{
	printf("Eroare: eroare citire pixeli");
}
