#include "Scaler.h"

Image Scaler::bmp_to_bytes(const char * file_path, uint16_t width, uint16_t height)
{
	return readBmp(file_path, width, height);
}

void Scaler::bmp_to_bytes(const char* file_path, uint16_t width, uint16_t height, Image* destination)
{
	*destination = readBmp(file_path, width, height);
}

Image Scaler::readBmp(const char* file_path, uint16_t width, uint16_t height) {
	FILE *f;
	fopen_s(&f, file_path, "rb");
	uint8_t * buffer = new uint8_t[width * height * 4];
	fseek(f, 54, SEEK_SET);
	fread(buffer, width * (height) * 4 * 4, 1, f);
	fclose(f);
	return Image(width, height, buffer);
}