#include <iostream>
#include <list>
#include <math.h>
#include <random>
#include <sstream> 
#include <fstream>
#include <ctime>
#include "Generator.cpp"
#include "Matrix.cpp"
//#include"Tree/Tree.hpp"
//#include "header.hpp"
using namespace std;

int main(int args,char* params[]){

	try{
		//Set random generator seed to current time
		srand(time(0));
		//Size of output image. 
		int size = 0;
		
		int randsize = 0;

		if(args==3){
			//read params from program input
			//--> generator.exe 200 100
			//will be generated random image with width and height eq to 200px and max range of random eq to 100
			stringstream sizestr(params[1]);
			stringstream randsizestr(params[2]);

			sizestr>>size;
			randsizestr>>randsize;

			//two underlines defines format of .pgm image
			ofstream file(string(params[2]).append(".pgm"));
			file<<"P2"<<'\n'<<size<<' '<<size<<'\n'<<randsize<<'\n';

			Generate_rand(size,randsize,file);
			file.close();
			return 0;
		}
		cout<<"First arg is size, second is the max value for random generator"<<endl;
		return 1;
	}
	catch(std::exception ex){
		std::cout<<ex.what();
		return 1;

	}


} 
