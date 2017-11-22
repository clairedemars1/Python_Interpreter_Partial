#include <iostream>

int main(){
	float lower_than_half =  -6.2;
	float above_half =  -6.7;
	int lower_than_half_int = lower_than_half;
	int above_half_int = above_half;
	std::cout<< lower_than_half_int << " " << above_half_int << std::endl;
	// both go to -6 (and not to -7, unlike python)
}
