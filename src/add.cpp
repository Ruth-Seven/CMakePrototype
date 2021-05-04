
#include "myproject/add.h"

int ADD1(int a, int b){
	return a + b;
}

class Add{
public :
	int operator()(int a, int b){
		return a + b;
	}
};


template<typename T, typename U>
auto ADD3(T a, U b) -> decltype(a + b){
	return a + b;
}

// ADD4 was decared in header files.  
// auto ADD4 = [](int a, int b)->int {
// 	return a + b;
// };
