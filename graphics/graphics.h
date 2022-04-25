#pragma once
#include <iostream>
#include <string>

namespace graphics{

	#define MAX_WIDTH 65536
	#define MAX_HEIGHT 65536

	struct RGB_Color{
		unsigned char r, g, b;
	};

	#define WHITE_COLOR {255, 255, 255}

	class BMPImage{
	private:
		size_t height;
		size_t width;
		RGB_Color **pixels;
	public:
		BMPImage();
		BMPImage(size_t, size_t);

		size_t get_height();
		void set_height(const size_t& Height);

		size_t get_width();
		void set_width(const size_t& Width);

		void set_pixel(size_t x, size_t y, RGB_Color color);
		RGB_Color get_pixel(size_t x, size_t y);

		void save_to_file(std::string filename);

	};

};