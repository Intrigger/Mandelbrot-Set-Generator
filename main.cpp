#include <iostream>
#include "graphics/graphics.h"
#include <random>

int main(){

	using std::cout;
	using std::endl;
	using namespace graphics;

	BMPImage img;

	img.set_height(1024); 
	img.set_width(1024);

	cout << img.get_width() << " " << img.get_height() << endl;

	int width = img.get_width();
	int height = img.get_height();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			int r = rand() % 256;
			img.set_pixel(x, y, {r, r, r});
		}
	}


	cout << (int)img.get_pixel(0, 0).r << " " << (int)img.get_pixel(0, 0).g << " " << (int)img.get_pixel(0, 0).b << endl;

	img.save_to_file("hello.bmp");

	return 0;
}