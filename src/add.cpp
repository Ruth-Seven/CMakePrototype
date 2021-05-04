
#include "add.hxx"

int ADD1(int a, int b){
	return a + b;
}

// 实现函数
int Add::operator()(int a, int b){
		return a + b;
}


