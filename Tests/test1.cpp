#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <string.h>

#include "Scaler.h"
#include "Image.h"
#include "Utils.h"

using namespace std;

int main() {
	Image img = Image::bmp_to_image("vs.bmp");

	//cout << "Image:" << endl << endl;

	//Utils::print_image(img);

	img = Scaler::scale_image(img, 2.5f);

	//cout << endl << endl << "Image x2:" << endl << endl;

	Image::image_to_bmp(img, "vs_testX2.5_0.bmp");

	//Utils::print_image(img);

	img = Scaler::scale_image(img, 0.4f);

	//cout << endl << endl << "Image scaled back to normal from x2:" << endl << endl;

	Image::image_to_bmp(img, "vs_testX2.5_1.bmp");

	//Utils::print_image(img);

	cout << endl;

	system("pause");

	return 0;
}