#include "graphics.h"

using namespace graphics;

BMPImage::BMPImage(){
	this->height = this->width = 0;
	pixels = nullptr;
}

BMPImage::BMPImage(size_t width, size_t height){
	this->width = width;
	this->height = height;
	this->pixels = new RGB_Color*[this->height];
	for (int i = 0; i < height; i++){
		pixels[i] = new RGB_Color[this->width];
	}
	for (int y = 0; y < this->height; y++){
		for (int x = 0; x < this->width; x++){
			pixels[y][x] = WHITE_COLOR;
		}
	}
}