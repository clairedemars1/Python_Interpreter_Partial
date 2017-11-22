#include <iostream>

int main(){
	float f = 0;
	float f2 = 0;
	int i = 0;
	
	std::cout << "equality is " << (f == f2 ) << std::endl;
	std::cout << "equality is " << (f == 0.0 ) << std::endl;
	std::cout << "equality is " << (f == 0 ) << std::endl;
	std::cout << "equality is " << (f == i ) << std::endl;
	std::cout << "true is " << true << std::endl;
}
