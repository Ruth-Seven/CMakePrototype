
#ifndef MYTEST_ADD

#define MYTEST_ADD


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;

int ADD1(int a, int b);

class Add{
public:
	int operator()(int a, int b);
};

static Add ADD2;


// C++模板把声明和定义都放在同一个头文件里，方便获取定义；
template<typename T, typename U>
auto ADD3(T a, U b) -> decltype(a + b){
	return a + b;
}

static auto ADD4 = [](int a, int b)->int {
	return a + b;
};


#endif