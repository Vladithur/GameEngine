#include "Colour.h"

using namespace std;

Colour::Colour()
{
}

Colour::Colour(uint8_t r, uint8_t g, uint8_t b)
{
	red = r;
	green = g;
	blue = b;
}


Colour::~Colour()
{
}

/*
	0 - all equal
	1 - red not equal
	2 - green not equal
	3 - blue not equal
	4 - red and green not equal
	5 - green and blue not equal
	6 - red and blue not equal
	7 - red, green and blue not equal
*/
uint8_t Colour::Equals(Colour col)
{
	uint8_t r = 0, g = 0, b = 0;
	if (red != col.red)
		r = 1;
	if (green != col.green)
		g = 2;
	if (blue != col.blue)
		b = 3;
	int temp = 0;
	if (r > 0 && g > 0 && b > 0) temp = -3;
	return r + g + b + (r > 0 && g > 0) + (r > 0 && b > 0) * 2 + temp;
}
