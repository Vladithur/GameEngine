#pragma once

#include "Scaler.h"

#include <stdint.h>

class Utils
{
private:
	Utils();
	~Utils();
public:
	static void print_colour(Colour col);
	static void colour_compare(Colour a, Colour b);
	static uint8_t colour_equals(Colour a, Colour b);
};

