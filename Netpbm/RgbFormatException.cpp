#include <iostream>
class RgbFormatException : std::exception{
    	const char * what () const throw ()
    {
    	return "Incorrect format of RGB pixel. Red<256 Green<256 Blue<256 !\n";
    }
};