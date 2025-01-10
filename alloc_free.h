//315CA-Neacsa Leonard
#include "image.h"

//Function that allocates memory for an image
image * alloc_image(void);

//Function that allocates memory for pixels in a image
void alloc_pixels(image *pic);

//Function that frees the memory
void free_image(image *pic);

//Function that frees a matrix
void free_matrix(int **a, int n);

//Function that allocs a matrix
int **alloc_matrix(int const *n, int const *m);

// Fucntion that frees the memory for struct matrix
void free_matrix_v2(matrix *a);

void free_init(image *pic);
