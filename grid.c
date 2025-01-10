//315CA-Neacsa Leonard
#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#include "alloc_free.h"
#define sigma 200
#define step 4

//Function that creates a matrix with the average value
//of the clors form the pixels
int **average_color_pixel(image *pic)
{
	int **inten;

	inten = alloc_matrix(&pic->n, &pic->m);
	if (!inten)
		return NULL;

	for (int i = 0; i < pic->n; i++)
		for (int j = 0; j < pic->m; j++)
			inten[i][j] = (int)(pic->pixel[i][j].R + pic->pixel[i][j].B
						+ pic->pixel[i][j].G) / 3;
	return inten;
}

//Function that creates grid based on the image
matrix *int_grid(image *pic, int x)
{
	int **inten = average_color_pixel(pic), n = pic->n / step + 1,
	m = pic->m / 4 + 1;
	matrix *grid = (matrix *)malloc(sizeof(matrix));

	grid->m = m;
	grid->n = n;
	grid->val = alloc_matrix(&n, &m);
	if (!inten)
		return NULL;
	if (!grid)
		return NULL;

	//Initialaize the grid matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			int k = 0, sum = 0;
			int ioffset = i * step, joffset = j * step;

			if (ioffset - 1 >= 0 && ioffset - 1 < pic->n &&
				joffset - 1 >= 0 && joffset - 1 < pic->m) {
				k++;
				sum += inten[ioffset - 1][joffset - 1];
			}
			if (ioffset - 1 >= 0 && ioffset - 1 < pic->n &&
				joffset + 1 >= 0 && joffset + 1 < pic->m) {
				k++;
				sum += inten[ioffset - 1][joffset + 1];
			}
			if (ioffset >= 0 && ioffset < pic->n &&
				joffset >= 0 && joffset < pic->m) {
				k++;
				sum += inten[ioffset][joffset];
			}
			if (ioffset + 1 >= 0 && ioffset + 1 < pic->n &&
				joffset - 1 >= 0 && joffset - 1 < pic->m) {
				k++;
				sum += inten[ioffset + 1][joffset - 1];
			}
			if (ioffset + 1 >= 0 && ioffset + 1 < pic->n &&
				joffset + 1 >= 0 && joffset + 1 < pic->m) {
				k++;
				sum += inten[ioffset + 1][joffset + 1];
			}
			if (sum / k <= sigma)
				grid->val[i][j] = 1;
			else
				grid->val[i][j] = 0;
		}
	}

	free_matrix(inten, pic->n);

	//If x is 1 it will show the contetns of the grid
	if (x == 1) {
		printf("Grid calculat cu succes [%d-%d]\n", pic->n / 4, pic->m / 4);
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				printf("%d ", grid->val[i][j]);
			}
			printf("\n");
		}
	}
	return grid;
}
