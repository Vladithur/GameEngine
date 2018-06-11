#pragma once

#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "Image.h"

class Scaler
{
public:
	static Image bmp_to_image(const char* file_path);
	static Image scale_image(Image src, uint16_t newW, uint16_t newH);
	static Image scale_image(Image src, float scaleFactor);
};