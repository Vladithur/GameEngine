#include "Image.h"


Image::Image()
{
	data = new uint8_t[0];
}


Image::Image(uint16_t w, uint16_t h)
{
	width = w;
	height = h;
}

Image::Image(uint16_t w, uint16_t h, uint8_t * d)
{
	width = w;
	height = h;
	data = d;
}

//your x/y starts from bottom left
Colour Image::GetPixel(uint16_t x, uint16_t y)
{
	int ind = (y * width + x) * 3;
	return Colour(data[ind + 2], data[ind + 1], data[ind]);
}

Image Image::bmp_to_image(const char * file_path)
{
	FILE * pFile;
	long lSize;
	uint8_t * buffer;
	size_t result;

	fopen_s(&pFile, file_path, "rb");
	if (pFile == NULL) { fputs("File error", stderr);}

	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	// allocate memory to contain the whole file:
	buffer = (uint8_t*)malloc(sizeof(uint8_t)*lSize);
	if (buffer == NULL) { fputs("Memory error", stderr);}

	// copy the file into the buffer:
	result = fread(buffer, 1, lSize, pFile);
	if (result != lSize) { fputs("Reading error", stderr);}

	/* the whole file is now loaded in the memory buffer. */


	uint16_t width = buffer[18];
	uint16_t height = buffer[22];
	uint8_t * data = new uint8_t[lSize - 54]; 
	std::copy(buffer + 54, buffer + lSize, data);

	Image * img = new Image(width, height, data);
	// terminate
	fclose(pFile);
	free(buffer);
	return *img;
}

void Image::image_to_bmp(Image src, const char* file_path)
{
	FILE * file;
	fopen_s(&file, file_path, "wb");
	if (!file)
		throw - 1;

	uint32_t size = src.width * src.height * 3;

	BITMAPINFOHEADER BMIH;
	BMIH.biSize = sizeof(BITMAPINFOHEADER);
	BMIH.biSizeImage = size;


	BMIH.biSize = sizeof(BITMAPINFOHEADER);
	BMIH.biWidth = src.width;
	BMIH.biHeight = src.height;
	BMIH.biPlanes = 1;
	BMIH.biBitCount = 24;
	BMIH.biCompression = BI_RGB;
	BMIH.biSizeImage = size;

	BITMAPFILEHEADER bmfh;
	int nBitsOffset = sizeof(BITMAPFILEHEADER) + BMIH.biSize;
	LONG lImageSize = BMIH.biSizeImage;
	LONG lFileSize = nBitsOffset + lImageSize;
	bmfh.bfType = 'B' + ('M' << 8);
	bmfh.bfOffBits = nBitsOffset;
	bmfh.bfSize = lFileSize;
	bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

	UINT nWrittenFileHeaderSize = fwrite(&bmfh, 1, sizeof(BITMAPFILEHEADER), file);
	UINT nWrittenInfoHeaderSize = fwrite(&BMIH, 1, sizeof(BITMAPINFOHEADER), file);

	UINT nWrittenDIBDataSize = fwrite(src.data, 1, lImageSize, file);
	fclose(file);
}

Image::~Image()
{
}

