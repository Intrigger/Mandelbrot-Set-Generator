#pragma once
#include <iostream>

namespace graphics{

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