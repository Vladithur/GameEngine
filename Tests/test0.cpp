#include "Scaler.h"
#include "Image.h"
#include "Utils.h"

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

int main() {
	Image img = Image::bmp_to_image("bmp0.bmp");

	cout << "Image:  ";
	Utils::print_image(img);

	Image::image_to_bmp(img, "bmp0_test.bmp");

	system("pause");
	return 0;
}