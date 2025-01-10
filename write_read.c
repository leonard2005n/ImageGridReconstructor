//315CA-Neacsa Leonard
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "image.h"
#include "alloc_free.h"

//Function that read a image
int read_image(image *pic)
{
	static int first_time = 1;
	int inval_pixel = 0;

	if (first_time == 0) {
		for (int i = 0; i < pic->n; i++) {
			free(pic->pixel[i]);
		}
		free(pic->pixel);
	} else {
		first_time = 0;
	}

	scanf("%s", pic->name);
	//Verify that the type of the image is valid
	if (strcmp(pic->name, "P3") != 0) {
		error_img_type();
		free(pic);
		pic = NULL;
		return 1;
	}

	scanf("%d%d%d", &pic->n, &pic->m, &pic->max_value);
	//Initialize the pixels dynamic with malloc
	alloc_pixels(pic);
	if (!pic) {
		return 1;
	}

	//Reading the values of the piexels
	int ok = 1;
	for (int i = 0; i < pic->n; i++) {
		for (int  j = 0; j < pic->m; j++) {
			ok = scanf("%d%d%d", &pic->pixel[i][j].R,
					   &pic->pixel[i][j].G, &pic->pixel[i][j].B);
			//Verify that the values of the pixels are valid
			if (ok < 3) {
				free_image(pic);
				pic = NULL;
				error_pixel_scan();
				return 1;
			}
			if (pic->pixel[i][j].R < 0 || pic->pixel[i][j].R > 255)
				inval_pixel = 1;
			if (pic->pixel[i][j].G < 0 || pic->pixel[i][j].G > 255)
				inval_pixel = 1;
			if (pic->pixel[i][j].B < 0 || pic->pixel[i][j].B > 255)
				inval_pixel = 1;
		}
	}

	if (!inval_pixel)
		printf("Imagine citita cu succes [%d-%d]\n", pic->n, pic->m);
	if (inval_pixel) {
		error_pixel_invalid();
		free_image(pic);
		pic = NULL;
		return 1;
	}
	return 0;
}

//Function that writes a image
void write_image(image *pic)
{
	printf("%s\n", pic->name);
	printf("%d %d\n%d\n", pic->n, pic->m, pic->max_value);
	for (int i = 0; i < pic->n; i++) {
		for (int  j = 0; j < pic->m; j++) {
			printf("%d %d %d\n", pic->pixel[i][j].R,
				   pic->pixel[i][j].G, pic->pixel[i][j].B);
		}
	}
}

