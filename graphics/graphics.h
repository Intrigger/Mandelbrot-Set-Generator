#pragma once
#include <iostream>

namespace graphics{

	#define MAX_WIDTH 65536
	#define MAX_HEIGHT 65536

	class BMPImage{
	private:
		size_t height;
		size_t width;
		int **pixels;
	public:
		BMPImage();
		BMPImage(size_t, size_t);

		size_t get_height();
		void set_height(const size_t& Height);

		size_t get_width();
		void set_width(const size_t& Width);

	};

};