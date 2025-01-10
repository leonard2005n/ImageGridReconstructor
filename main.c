//315CA-Neacsa Leonard
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#include "alloc_free.h"
#include "write_read.h"
#include "errors.h"
#include "functions.h"

int main(void)
{
	image *pic = alloc_image(), *contur;
	int ok = 0, grid_done = 0, init = 0;
	matrix *grid;
	char c[11];

	if (!pic) {
		return 1;
	}

	scanf(" %s", c);
	//Determine what function to call
	while (strcmp(c, "EXIT") != 0) {
		if (strcmp(c, "WRITE") == 0) {
			write_image(pic);
		} else if (strcmp(c, "READ") == 0) {
			ok = read_image(pic);
			if (!pic || ok)
				return 0;
		} else if (strcmp(c, "GRID") == 0) {
			if (grid_done)
				free_matrix_v2(grid);
			grid = int_grid(pic, 1);
			if (!grid)
				return 0;
			grid_done = 1;
		} else if (strcmp(c, "RESIZE") == 0) {
			pic = resize(pic);
		} else if (strcmp(c, "INIT_CONTUR") == 0) {
			contur = init_contur(1);
			init = 1;
		} else if (strcmp(c, "MARCH") == 0) {
			pic = march(pic);
		}
		scanf(" %s", c);
	}

	printf("Gigel a terminat\n");

	//Frees the memory that was used
	if (init) {
		for (int i = 0; i < 16; i++) {
			free_init(&contur[i]);
		}
		free(contur);
	}

	if (grid_done)
		free_matrix_v2(grid);
	free_image(pic);
	return 0;
}
