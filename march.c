//315CA-Neacsa Leonard
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "alloc_free.h"
#include "write_read.h"
#include "image.h"
#define step 4

image *march(image *pic)
{
	matrix *grid = int_grid(pic, 0);
	image *init = init_contur(0), *tmp = alloc_image();

	//Copying information from the previous image
	strcpy(tmp->name, "P3");
	tmp->m = pic->m;
	tmp->n = pic->n;
	tmp->max_value = 255;
	alloc_pixels(tmp);

	//Creating a new image based on the marching squares
	//algorithm
	for (int i = 0; i < grid->n - 1; i++) {
		for (int j = 0; j < grid->m - 1; j++) {
			int sum =  8 * grid->val[i][j] + 4 * grid->val[i][j + 1] +
			 2 * grid->val[i + 1][j + 1] + grid->val[i + 1][j];
			int ioffset = i * step, joffset = j * step;
			for (int a = ioffset; a < ioffset + 4; a++) {
				for (int b = joffset; b < joffset + 4; b++) {
					tmp->pixel[a][b].R =
					init[sum].pixel[a - ioffset][b - joffset].R;
					tmp->pixel[a][b].B =
					init[sum].pixel[a - ioffset][b - joffset].B;
					tmp->pixel[a][b].G =
					init[sum].pixel[a - ioffset][b - joffset].G;
				}
			}
		}
	}

	//Freeing the information need for the marching squares
	free_matrix_v2(grid);
	for (int i = 0; i < 16; i++) {
		free_init(&init[i]);
	}
	free(init);
	free_image(pic);

	printf("Marching Squares aplicat cu succes [%d-%d]\n", tmp->n, tmp->m);
	return tmp;
}
