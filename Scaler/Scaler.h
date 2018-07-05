#pragma once

#include <stdint.h>
#include <cstdio>
#include <cmath>

#include "Image.h"

class Scaler
{
public:
	static Image scale_image(Image src, uint16_t newW, uint16_t newH);
	static Image scale_image(Image src, float scaleFactor);
};