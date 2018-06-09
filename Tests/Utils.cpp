#include "Utils.h"


Utils::~Utils()
{
}

void Utils::print_colour(Colour col)
{
	uint16_t r = col.red;
	uint16_t g = col.green;
	uint16_t b = col.blue;
	cout << " ( r : " << r << "  g : " << g << "  b : " << b << " ) ";
}

void Utils::colour_compare(Colour exp, Colour got)
{
	cout << "Expected";
	print_colour(exp);
	cout << "and got";
	print_colour(got);
	cout << endl;
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
uint8_t Utils::colour_equals(Colour a, Colour b)
{
	uint8_t r = 0, g = 0, bl = 0;
	if (a.red != b.red)
		r = 1;
	if (a.green != b.green)
		g = 2;
	if (a.blue != b.blue)
		bl = 3;
	int temp = 0;
	if (r > 0 && g > 0 && bl > 0) temp = -3;
	return r + g + bl + (r > 0 && g > 0) + (r > 0 && bl > 0) * 2 + temp;
}
