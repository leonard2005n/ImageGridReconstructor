//315CA-Neacsa Leonard
#pragma once

//A struct that retains the values of a pixel
typedef struct {
	int R, G, B;
} pixels;

//A struct that retains the values of a image
typedef struct {
	char name[10];
	int n, m;
	int max_value;
	pixels **pixel;
} image;

typedef struct {
	int n, m;
	int **val;
} matrix;
