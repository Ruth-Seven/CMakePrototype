#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "jtest/jtest.hpp"
// #include "gtest/gtest.h"
#include "add.hxx"
using namespace std;


#define ISIGNORE_LOG // 禁止LOG功能	
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

TEST(HelloTest2, ADD2){
    LOG("test2")
	EXPECT_EQ(ADD2(3,4), 7);
	EXPECT_NE(ADD2(3,4), 6);
	EXPECT_LT(ADD2(3,4), 3);
	EXPECT_LE(ADD2(3,4), 7);
	EXPECT_GT(ADD2(3,4), 6);
	EXPECT_GE(ADD2(3,4), 7);

}

TEST(HelloTest3, ADD3){
    LOG("test3")
	EXPECT_EQ(ADD3(3,4), 7);
	EXPECT_NE(ADD3(3,4), 6);
	EXPECT_LT(ADD3(3,4), 3);
	EXPECT_LE(ADD3(3,4), 7);
	EXPECT_GT(ADD3(3,4), 6);
	EXPECT_GE(ADD3(3,4), 7);

}

TEST(HelloTest4, ADD4){
    LOG("test4")
	EXPECT_EQ(ADD4(3,4), 7);
	EXPECT_NE(ADD4(3,4), 6);
	EXPECT_LT(ADD4(3,4), 3);
	EXPECT_LE(ADD4(3,4), 7);
	EXPECT_GT(ADD4(3,4), 6);
	EXPECT_GE(ADD4(3,4), 7);

}

int main(){

	
	printf("\033[4;34;mBegin test!\n\033[0m");
	// testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
