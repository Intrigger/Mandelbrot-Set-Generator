#include <iostream>
#include "graphics/graphics.h"


int main(){

	using std::cout;
	using std::endl;
	using namespace graphics;

	BMPImage img;

	img.set_height(1246345623);
	img.set_width(1246345623);

	cout << img.get_height() << endl;
	cout << img.get_width() << endl;

	cout << MAX_WIDTH;

	return 0;
}