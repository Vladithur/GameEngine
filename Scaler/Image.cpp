#include "Image.h"

Image::Image()
{
}


Image::Image(int w, int h, unsigned int * d)
{
	width = w;
	height = h;
	data = d;
}

unsigned int Image::GetPixel(int x, int y)
{
	//assuming your x/y starts from top left
	return data[(height - y) * width + x];
}

Image::~Image()
{
}

