#include "Scaler.h"

void Scaler::bmp_to_bytes(char * file_path, int width, int height, Image * destination)
{
	FILE *f = fopen(file_path, "rb");
	unsigned int* buffer = new unsigned int[width * height];
	fread(buffer, 132 * 65 * 4, 1, f);
	fclose(f);
	*destination->data = *buffer;
}