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
	int iterations = 1000;
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
	using namespace graphics;

	BMPImage img;

	int width = 900;
	int height = 900;



	double centerx = -0.75;
	double centery = 0.0;
	double real_width = 1.0;
	double real_height = 1.0;

	double c = 0.01;

	int images_number = 60*60;

	for (int t = 0; t < images_number; t++){

		img.set_height(height); 
		img.set_width(height);

		for (int y = 0; y < height; y++){
			for (int x = 0; x < width; x++){
				float fx = (centerx - (real_width / 2.0) + (double(x) / double(width) * real_width));
				float fy = (centery - (real_height / 2.0) + (double(y) / double(height) * real_height));
				if (check_mandelbrot({fx, fy}, t)){
					img.set_pixel(x, y, {0, 0, 0});
				}
				
			}
		}

		real_width *= 0.9;
		real_height *= 0.9;

		cout << "Image #" << t + 1 << endl;

		img.save_to_file("pictures/mandelbrot_set_" + std::to_string(t + 1) + ".bmp");
		img.clear();
	}

	

	return 0;
}