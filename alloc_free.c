//315CA-Neacsa Leonard
#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#include "errors.h"

//Function that allocates memory for an image
image *alloc_image(void)
{
	image *pic = (image *)malloc(sizeof(image));
	if (!pic) {
		fprintf(stderr, "alloc_image()error\n");
		return NULL;
	}
	return pic;
}

//Function that allocates memory for pixels in a image
void alloc_pixels(image *pic)
{
	pic->pixel = (pixels **) malloc(pic->n * sizeof(pixels *));
	if (!pic->pixel) {
		fprintf(stderr, "alloc_pixels()error\n");
		error_pixel_scan();
		free(pic);
		pic = NULL;
		return;
	}

	//Allocs the memory for the pixles in the image
	for (int i = 0; i < pic->n; i++) {
		pic->pixel[i] = (pixels *) malloc(sizeof(pixels) * pic->m);
		if (!pic->pixel[i]) {
			for (int j = i - 1; j >= 0; j--) {
				free(pic->pixel[j]);
			}
			free(pic);
			pic = NULL;
			return;
		}
	}
}

//Function that frees the memory
void free_image(image *pic)
{
	for (int i = 0; i < pic->n; i++) {
		free(pic->pixel[i]);
	}
	free(pic->pixel);
	free(pic);
}

//Function that frees a matrix
void free_matrix(int **a, int n)
{
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

//Function that allocs a matrix
int **alloc_matrix(int const *n, int const *m)
{
	int **tmp = (int **)malloc(*n * sizeof(int *));
	if (!tmp) {
		fprintf(stderr, "alloc_matrix()error\n");
		free(tmp);
		return NULL;
	}

	for (int i = 0; i < *n; i++) {
		tmp[i] = (int *)malloc(*m * sizeof(int));
		if (!tmp) {
			fprintf(stderr, "alloc_matrix()error\n");
			for (int j = i - 1; j >= 0; j--)
				free(tmp[j]);
			free(tmp);
			return NULL;
		}
	}
	return tmp;
}

//Fucntion that frees the memory for struct matrix
void free_matrix_v2(matrix *a)
{
	for (int i = 0; i < a->n; i++) {
		free(a->val[i]);
	}
	free(a->val);
	free(a);
}

//Function that frees the init_contur image
void free_init(image *pic)
{
	for (int i = 0; i < pic->n; i++) {
		free(pic->pixel[i]);
	}
	free(pic->pixel);
}
