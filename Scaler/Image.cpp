#include "Image.h"


Image::Image()
{
	data = new uint8_t[0];
}


Image::Image(uint16_t w, uint16_t h)
{
	width = w;
	height = h;
}

Image::Image(uint16_t w, uint16_t h, uint8_t * d)
{
	width = w;
	height = h;
	data = d;
}

//your x/y starts from bottom left
Colour Image::GetPixel(uint16_t x, uint16_t y)
{
	int ind = (y * width + x) * 3;
	return Colour(data[ind + 2], data[ind + 1], data[ind]);
}

Image::~Image()
{
}

