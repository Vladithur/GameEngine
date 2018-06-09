#include "Scaler.h"
#include "Image.h"
#include "Utils.h"

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

	cout << "Pixel 0 0:  ";
	Utils::colour_compare(exp00, pix00);
	cout << "Pixel 1 0:  ";
	Utils::colour_compare(exp10, pix10);
	cout << "Pixel 0 1:  ";
	Utils::colour_compare(exp01, pix01);
	cout << "Pixel 1 1:  ";
	Utils::colour_compare(exp11, pix11);

	system("pause");
	return 0;
}