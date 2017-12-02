#include <iostream>
using std::endl;
using std::cout;
#include <vector>

class myClass{
public:
	void foo(){ cout << "in foo" << endl; }
};

int main(){
	std::vector<myClass> vec;
	vec.push_back( myClass() );
	cout << " vec size " << vec.size() << endl;
	cout << "watch me call the foo function on an object that doesn't exist" << endl;
	vec[1].foo();
}
