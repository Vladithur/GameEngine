#pragma once

#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "Image.h"

class Scaler
{
private: 
	static Image readBmp(const char* file_path, uint16_t width, uint16_t height);
public:
	static Image bmp_to_bytes(const char* file_path, uint16_t width, uint16_t height);
	static void bmp_to_bytes(const char* file_path, uint16_t width, uint16_t height, Image* destination);
	static Image scale(Image src, uint16_t newW, uint16_t newH);
};