#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <fmt/format.h>
#include "add.hxx"
using namespace std;


// void print(int a, int b);
int main(){
	Add ADD2;
	cout << ADD1(3,4) << endl;	
	cout << ADD2(3,4) << endl;	
	cout << ADD3(3,4) << endl;	
	cout << ADD4(3,4) << endl;
	fmt::print("ADD1: {} ADD2: {} \n", ADD1(3,4), ADD2(3,4));	
	fmt::print("ADD3: {} ADD4: {} \n", ADD3(3,4), ADD4(3,4));	
	// print(3, 4);
	return 0;
}
