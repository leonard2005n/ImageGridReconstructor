//315CA-Neacsa Leonard
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alloc_free.h"
#include "image.h"

//Function that resize the image
image  *resize(image *pic)
{
	image *tmp = alloc_image();

	if (!tmp) {
		tmp = NULL;
		free_image(pic);
		pic = NULL;
		return pic;
	}
	strcpy(tmp->name, pic->name);

	tmp->max_value = pic->max_value;
	tmp->n = pic->n * 4;
	tmp->m = pic->m * 4;

	alloc_pixels(tmp);
	if (!tmp) {
		tmp = NULL;
		free_image(pic);
		pic = NULL;
		return pic;
	}

	//Reconstruct the image
	for (int i = 0; i < pic->n; i++) {
		for (int j = 0; j < pic->m; j++) {
			for (int a = i * 4; a < i * 4 + 4; a++) {
				for (int b = j * 4; b < j * 4 + 4; b++) {
					tmp->pixel[a][b] = pic->pixel[i][j];
				}
			}
		}
	}
	printf("Imagine redimensionata cu succes [%d-%d]\n", tmp->n, tmp->m);
	free_image(pic);
	return tmp;
}
