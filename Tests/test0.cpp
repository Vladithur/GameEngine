#include "Scaler.h"
#include "Image.h"

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

int main() {
	Image img = Scaler::bmp_to_bytes("bmp0.bmp", 4, 4);
	Colour pix00 = img.GetPixel(0, 0);
	Colour pix10 = img.GetPixel(1, 0);
	Colour pix01 = img.GetPixel(0, 1);
	Colour pix11 = img.GetPixel(1, 1);

	Colour exp00 = Colour(255, 255, 255);
	Colour exp10 = Colour(0, 0, 0);
	Colour exp01 = Colour(0, 0, 0);
	Colour exp11 = Colour(255, 255, 255);

	uint16_t a = pix00.Equals(exp00);
	uint16_t b = pix10.Equals(exp10);
	uint16_t c = pix01.Equals(exp01);
	uint16_t d = pix11.Equals(exp11);

	cout << "Pixel 0 0: " << a << endl;
	cout << "Pixel 1 0: " << b << endl;
	cout << "Pixel 0 1: " << c << endl;
	cout << "Pixel 1 1: " << d << endl;

	system("pause");
	return 0;
}