
#ifndef MYTEST_ADD

#define MYTEST_ADD


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;

int ADD1(int a, int b);

class Add;

template<typename T, typename U>
auto ADD3(T a, U b) -> decltype(a + b);

static auto ADD4 = [](int a, int b)->int {
	return a + b;
};


#endif