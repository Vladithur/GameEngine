#pragma once

#include <stdio.h>

#include "Colour.h"

class Image
{
public:
	uint8_t * data;
	uint16_t width;
	uint16_t height;
	Image();
	Image(uint16_t w, uint16_t h);
	Image(uint16_t w, uint16_t h, uint8_t * d);
	Colour GetPixel(uint16_t x, uint16_t y);
	~Image();
};

