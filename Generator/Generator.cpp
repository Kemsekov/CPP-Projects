#include <fstream>
#include <iostream>
template<typename T>
int Generate_rand(int size,int Intervall,T &file){
	uint seed = uint(pow(time(0),2))%rand();
	srand(seed);
	try{
		{

		short buf = 0;
		for(int a = 0;a<size;a++){
			srand(time(0)*a);
			for(int b = 0;b<size;b++){
				buf = static_cast<short>(rand()%Intervall);
				file<<buf<<' ';
			}
			file<<'\n';
		}
		}
		return 0;
	}
	catch(std::exception ex){
		std::cout<<ex.what();
		return 1;

} 
}