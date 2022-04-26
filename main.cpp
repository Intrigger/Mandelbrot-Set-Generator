#include <iostream>
#include "graphics/graphics.h"
#include <random>
#include <time.h>

struct complex_number{
	double real;
	double imaginary;
};

bool check_mandelbrot(complex_number c, int iteration){
	complex_number z0 = {0, 0};
	int iterations = 100;
	for (int i = 0; i < iterations; i++){
		z0 = {z0.real * z0.real - z0.imaginary * z0.imaginary + c.real, 2 * z0.real * z0.imaginary + c.imaginary};
	}

	double border = 10.0;
 
	return sqrt(z0.real * z0.real + z0.imaginary * z0.imaginary) < border;

}


int main(){

	srand(time(0));

	using std::cout;
	using std::endl;
	using std::cin;
	using namespace graphics;

	BMPImage img;

	int width = 1024;
	int height = 1024;

	double centerx = -0.75;
	double centery = 0.0;
	double real_width = 2.0;
	double real_height = 2.0;

	system("clear");

	cout << "Welcome!\n"
		 << "This program can draw a Madnelbrot`s set and save it`s picture to a .bmp file.\n";
	cout << "First of all, enter image width (px): ";
	cin >> width;

	cout << "Secondly, enter the image height (px): ";
	cin >> height;

	cout << "Enter the real width of the image (it real size on the plane of numbers): ";
	cin >> real_width;

	cout << "And finally enter the real height of the image: ";
	cin >> real_height;


	img.set_height(height); 
	img.set_width(width);

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			double fx = (centerx - (real_width / 2.0) + ((double(x) / double(width)) * real_width));
			double fy = (centery - (real_height / 2.0) + ((double(y) / double(height)) * real_height));
			if (check_mandelbrot({fx, fy}, 1)){
				img.set_pixel(x, y, {0, 0, 0});
			}
			
		}
	}

	img.save_to_file("pictures/mandelbrot_set.bmp");

	

	return 0;
}