#pragma once

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>

using namespace std;


class Colour
{
public:
	uint8_t red, green, blue;
	Colour();
	Colour(uint8_t r, uint8_t g, uint8_t b);
	~Colour();
	uint8_t Equals(Colour b);
};

