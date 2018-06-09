#pragma once

#include <float.h>
#include <string.h>
#include <stdio.h>

#include "Image.h"

static class Scaler
{
public:
	void bmp_to_bytes(char* file_path, int width, int height, Image* destination);
};