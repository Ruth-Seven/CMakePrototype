#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <fmt/format.h>
using namespace std;

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
auto ADD4 = [](int a, int b)->int {
	return a + b;
};

// void print(int a, int b);
int main(){
	Add ADD2;
	cout << ADD1(3,4) << endl;	
	cout << ADD2(3,4) << endl;	
	cout << ADD3(3,4) << endl;	
	cout << ADD4(3,4) << endl;
	fmt::print("ADD1: {} ADD2: {} \n", ADD1(3,4), ADD2(3,4));	
	// print(3, 4);
	return 0;
}
