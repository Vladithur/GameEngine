#include "Scaler.h"

Image Scaler::readBmp(const char* file_path, uint16_t width, uint16_t height) {
	FILE * f;
	fopen_s(&f, file_path, "rb");
	uint8_t * buffer = new uint8_t[width * height * 4];
	fseek(f, 54, SEEK_SET);
	fread(buffer, width * (height) * 4 * 4, 1, f);
	fclose(f);
	return Image(width, height, buffer);
}

Image Scaler::bmp_to_bytes(const char * file_path, uint16_t width, uint16_t height)
{
	return readBmp(file_path, width, height);
}

void Scaler::bmp_to_bytes(const char* file_path, uint16_t width, uint16_t height, Image* destination)
{
	*destination = readBmp(file_path, width, height);
}

Image Scaler::scale(Image src, uint16_t newW, uint16_t newH)
{
	Image sclImg = Image();
	sclImg.width = newW;
	sclImg.height = newH;

	uint16_t width = src.width;
	uint16_t height = src.height;
	uint8_t * oldData = src.data;
	float moveX = newW / width;
	float moveY = newH / height;
	uint8_t * newData = new uint8_t[newW * newH * 3];

	uint16_t oldX = 0;
	float newX = 0;
	while (oldX < width) {

		uint16_t oldY = 0;
		float newY = 0;

		uint16_t rnd_newX = lroundf(newX);

		while (oldY < height) {

			uint16_t rnd_newY = lroundf(newY);
			int ind = (oldY * width + oldX) * 3;
			int newInd = (rnd_newY * newW + rnd_newX) * 3;

			newData[newInd] = oldData[ind];

			newY += moveY;
			oldY++;
		}

		newX += moveX; 
		oldX++;
	}
	return Image(newW, newH, newData);
}