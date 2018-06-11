#include "Scaler.h"
#include "Image.h"
#include "Utils.h"

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

int main() {
	Image img = Scaler::bmp_to_bytes("bmp0.bmp");

	cout << "Image:";
	Utils::print_image(img);

	system("pause");
	return 0;
}