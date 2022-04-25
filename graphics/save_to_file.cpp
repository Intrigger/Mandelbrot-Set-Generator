#include "graphics.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace graphics;

void BMPImage::save_to_file(std::string filename){
	std::ofstream os(filename.c_str(), std::ios::binary);

	unsigned char signature[2] = { 'B', 'M' };
	unsigned int fileSize = 14 + 40 + this->height*this->width*4;
	unsigned int reserved = 0;
	unsigned int offset = 14 + 40;

	unsigned int headerSize = 40;
	unsigned int dimensions[2] = { (unsigned int)this->width, (unsigned int)this->height };
	unsigned short colorPlanes = 1;
	unsigned short bpp = 32;
	unsigned int compression = 0;
	unsigned int imgSize = this->width*this->height*4;
	unsigned int resolution[2] = { 2795, 2795 };
	unsigned int pltColors = 0;
	unsigned int impColors = 0;

	os.write(reinterpret_cast<char*>(signature), sizeof(signature));
	os.write(reinterpret_cast<char*>(&fileSize), sizeof(fileSize));
	os.write(reinterpret_cast<char*>(&reserved), sizeof(reserved));
	os.write(reinterpret_cast<char*>(&offset),   sizeof(offset));

	os.write(reinterpret_cast<char*>(&headerSize),  sizeof(headerSize));
	os.write(reinterpret_cast<char*>(dimensions),   sizeof(dimensions));
	os.write(reinterpret_cast<char*>(&colorPlanes), sizeof(colorPlanes));
	os.write(reinterpret_cast<char*>(&bpp),         sizeof(bpp));
	os.write(reinterpret_cast<char*>(&compression), sizeof(compression));
	os.write(reinterpret_cast<char*>(&imgSize),     sizeof(imgSize));
	os.write(reinterpret_cast<char*>(resolution),   sizeof(resolution));
	os.write(reinterpret_cast<char*>(&pltColors),   sizeof(pltColors));
	os.write(reinterpret_cast<char*>(&impColors),   sizeof(impColors));

	unsigned char x,r,g,b;

	for (int i=0; i < dimensions[1]; i++)
	{
		for (int j=0; j < dimensions[0]; j++)
		{
			x = 0;
			r = pixels[i][j].r;
			g = pixels[i][j].g;
			b = pixels[i][j].b;
			os.write(reinterpret_cast<char*>(&b),sizeof(b));
			os.write(reinterpret_cast<char*>(&g),sizeof(g));
			os.write(reinterpret_cast<char*>(&r),sizeof(r));
			os.write(reinterpret_cast<char*>(&x),sizeof(x));
		}
	}

	os.close();
}