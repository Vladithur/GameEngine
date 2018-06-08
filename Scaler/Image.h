#pragma once

#include <stdio.h>
class Image
{
public:
	int width;
	int height;
	unsigned int* data;
	Image();
	Image(int w, int h, unsigned int* data);
	unsigned int GetPixel(int x, int y);
	~Image();
};

