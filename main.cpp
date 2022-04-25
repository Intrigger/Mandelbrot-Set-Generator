#include <iostream>
#include "graphics/graphics.h"


int main(){

	using std::cout;
	using std::endl;
	using namespace graphics;

	BMPImage img;

	img.set_height(256);
	img.set_width(512);

	cout << img.get_height() << endl;
	cout << img.get_width() << endl;

	return 0;
}