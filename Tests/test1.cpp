#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <string.h>

#include "Scaler.h"
#include "Image.h"
#include "Utils.h"

using namespace std;

int main() {
	Image img = Image::bmp_to_image("bmp0.bmp");

	cout << "Image:" << endl << endl;

	Utils::print_image(img);

	img = Scaler::scale_image(img, 2);

	cout << endl << endl << "Image x2:" << endl << endl;

	Image::image_to_bmp(img, "bmp0_testX2_0.bmp");

	Utils::print_image(img);

	img = Scaler::scale_image(img, 0.5f);

	cout << endl << endl << "Image scaled back to normal from x2:" << endl << endl;

	Image::image_to_bmp(img, "bmp0_testX2_1.bmp");

	Utils::print_image(img);

	cout << endl;

	system("pause");

	return 0;
}