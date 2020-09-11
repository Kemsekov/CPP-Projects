#pragma once
#include <fstream>
#include <vector>
#include "RGB.cpp"

void CreatePPM(int colorsize,std::vector<std::vector<RGB>> vc,std::string filename = "image.ppm"){
	int size_x = vc.size();
	int size_y = vc[0].size();
	std::ofstream file = std::ofstream(filename);
	file<<"P3"<<'\n'<<size_x<<' '<<size_y<<'\n'<<colorsize<<'\n';
	for(auto a : vc){
		for(auto b : a){
			file<<b.R<<' '<<b.G<<' '<<b.B<<'\n';
		}
	}
}
void CreatePGM(int colorsize,std::vector<std::vector<int>> vc,std::string filename = "image.ppm"){
    int size_x = vc.size();
	int size_y = vc[0].size();
	std::ofstream file = std::ofstream(filename);
	file<<"P2"<<'\n'<<size_x<<' '<<size_y<<'\n'<<colorsize<<'\n';
	for(auto a : vc){
		for(auto b : a){
			file<<b<<' ';
		}
	}
}