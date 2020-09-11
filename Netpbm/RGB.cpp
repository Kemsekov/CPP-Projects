#pragma once
#include "RgbFormatException.cpp"
class RGB{
	public:
	short R = 0;
	short G = 0;
	short B = 0;
	RGB(short r, short g, short b){
		if(r<256 && g<256 && b<256){
		R = r;
		G = g;
		B = b;
		}
		else {
			throw RgbFormatException();
		}
	}
};