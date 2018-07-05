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

	cout << "Running scaling x2 then back on 4x4 100000 times:" << endl;

	for (int i = 0; i < 100000; i++) {
		img = Scaler::scale_image(img, 2);
		img = Scaler::scale_image(img, 0.5f);
	}

	cout << endl;

	system("pause");

	return 0;
}