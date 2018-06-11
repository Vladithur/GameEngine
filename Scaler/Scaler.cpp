#include "Scaler.h"

using namespace std;

Image Scaler::bmp_to_image(const char * file_path)
{
	FILE * f;
	fopen_s(&f, file_path, "rb");
	uint32_t * temp = new uint32_t[2];
	fseek(f, 18, SEEK_SET);
	fread(temp, 8, 1, f);
	uint16_t width = temp[0];
	uint16_t height = temp[1];
	uint8_t * buffer = new uint8_t[width * height * 4];
	fseek(f, 54, SEEK_SET);
	fread(buffer, width * (height) * 4 * 4, 1, f);
	fclose(f);
	Image img = Image(width, height, buffer);
	delete[] buffer;
	delete[] temp;
	return img;
}

Image Scaler::scale_image(Image src, uint16_t newW, uint16_t newH)
{

	float moveX = (float)src.width / (float)newW;
	float moveY = (float)src.height / (float)newH;
	if (moveX < 2 && moveY < 2) {
		uint16_t width = src.width;
		uint16_t height = src.height;
		//uint8_t ** oldData = &src.data;
		uint8_t * newData = new uint8_t[newW * newH * 3];

		float oldX = 0;
		uint16_t newX = 0;
		while (newX < newW) {

			float oldY = 0;
			uint16_t newY = 0;

			uint16_t rnd_oldX = roundf(oldX);

			while (newY < newH) {

				uint16_t rnd_oldY = roundf(oldY);
				int ind = (rnd_oldY * width + rnd_oldX) * 3;
				int newInd = (newY * newW + newX) * 3;
				/*uint8_t a = oldData[ind];
				uint8_t b = oldData[ind + 1];
				uint8_t c = oldData[ind + 2];
				newData[newInd] = a;
				newData[newInd + 1] = b;
				newData[newInd + 2] = c;*/
				newData[newInd] = src.data[ind];
				newData[newInd + 1] = src.data[ind + 1];
				newData[newInd + 2] = src.data[ind + 2];

				oldY = oldY + moveY;
				newY++;
			}

			oldX = oldX + moveX;
			newX++;
		}
		src.data = newData;
		delete[] newData;
		src.width = newW;
		src.height = newH;
		return src;
	}
	else if (moveX == 2 || moveY == 2) {
		return scale_image(scale_image(src, (float)newW * 1.5f, (float)newH * 1.5f), newW, newH);
	}
	else {
		return scale_image(scale_image(src, newW * 2, newH * 2), newW, newH);
	}
}

Image Scaler::scale_image(Image src, float scaleFactor)
{
	return scale_image(src, (float)src.width * scaleFactor, (float)src.height * scaleFactor);
}
