#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
// #include "jtest/jtest.h"
#include "gtest/gtest.h"
#include "./add.h"
using namespace std;



// 单元测试样例
TEST(HelloTest1, ADD1){
    LOG("test1")
	EXPECT_EQ(ADD1(3,4), 7);
	EXPECT_NE(ADD1(3,4), 6);
	EXPECT_LT(ADD1(3,4), 8);
	EXPECT_LE(ADD1(3,4), 7);
	EXPECT_GT(ADD1(3,4), 6);
	EXPECT_GE(ADD1(3,4), 7);

}

/// 单元测试样例
TEST(HelloTest2, ADD3){
    LOG("test3")
	EXPECT_EQ(ADD3(3,4), 7);
	EXPECT_NE(ADD3(3,4), 6);
	EXPECT_LT(ADD3(3,4), 3);
	EXPECT_LE(ADD3(3,4), 7);
	EXPECT_GT(ADD3(3,4), 6);
	EXPECT_GE(ADD3(3,4), 7);

}
int main(){
	begin();
	for_each()
	printf("\033[0;33;44m"); 
	printf("hello test!\n");
	printf("\033[4;34;46m hello world!\n");
	// testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
