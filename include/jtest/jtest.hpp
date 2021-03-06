
#ifndef _JTEST_H

#define _JTEST_H

// #define ISIGNORE_LOG //忽略非标准输出 LOG
#include <cstdio>
#include <ctime>
#include <cstring>
#include <tuple>



#define COLOR_MSG(msg, color) "\033[0;" #color "m" msg "\033[0;m"
#define RED(msg)    COLOR_MSG(msg, 31)
#define GREEN(msg)  COLOR_MSG(msg, 32)
#define YELLOW(msg) COLOR_MSG(msg, 33)
#define BLUE(msg)   COLOR_MSG(msg, 34)



#define EXPECT_CMP(a, cmp, b) { \
    if(!(a cmp b)){ \
        printf("\t%s\n", FAILURE); \
        printf(YELLOW("\t %s:%d"), __FILE__, __LINE__); \
        printf(YELLOW("\t\tExpected: (%s %s %s), actual %d vs %d\n"), #a, #cmp, #b, a, b);\
        /*通过在头文件引入外部变量，解决标志值问题。倘若在头文件定义变量则会有静态（文件链接）变量备份不唯一，或者非静态（外部链接）变量多重定义的问题*/ \
        extern int testflag;\
        testflag = 0;\
    } \
}
#define EXPECT_EQ(a, b) EXPECT_CMP(a, ==, b)
#define EXPECT_NE(a, b) EXPECT_CMP(a, !=, b)
#define EXPECT_LT(a, b) EXPECT_CMP(a, <, b)
#define EXPECT_LE(a, b) EXPECT_CMP(a, <=, b)
#define EXPECT_GT(a, b) EXPECT_CMP(a, >, b)
#define EXPECT_GE(a, b) EXPECT_CMP(a, >=, b)



// 最精妙的设计
// 为每一个TEST宏独立自动扩展成TEST函数，并设置注册函数
#define TEST_FUNC_NAME(a, b) JJ_TEST_##a##_##b // concatenate strings.
#define TEST(a, b) \
void TEST_FUNC_NAME(a, b)(); /*声明单元测试函数*/ \
 __attribute__((constructor)) /*为单元测试函数声明注册函数*/ \
void INVOKE_##a##_##b(){ \
    char *name = new char(size(#a "." #b)); \
    strcpy(name, #a "." #b); \
    /*printf("@@@@%s %p\n", name, name); */  \
    add_funcdata(TEST_FUNC_NAME(a, b), name); \
} \
void TEST_FUNC_NAME(a, b)() 

//void __attribute__((destructor)) calledLast(); 
// This particular GCC syntax, when used with a function, executes the same function at the startup of the program, i.e before main() function.



// Link node struct
struct FuncData{
    // 函数指针数组
    void (*func)(); // [] > * funcarr首先是个数组，其次是指针
    char *funcname;
    FuncData* next;

    FuncData(void (*func)(), char* name);
    ~FuncData();
};

struct FuncInfo{
    FuncData *head;
    FuncData *tailp;
    int curtest;
private:
    FuncData *now;

public:
    FuncInfo();
    void add(void (*func)(), char *name);
    bool hasNext();
    std::pair<void (*)(), char *> visit();
    // 把注销信息的功能托付给 信息管理类，将自动程序结束时，删除动态分配的信息
    ~FuncInfo();
};


// 被注册函数所调用，添加被注册test函数信息
void add_funcdata(void (*func)(), char *funcname);
// 删除动态生成的字符串内容，防止内存泄漏
void delete_funcdata();


//运行所有被注册test函数
int RUN_ALL_TESTS();

// Info string
static const char * RUN  =      GREEN("[  RUN     ]");
static const char * OK  =       GREEN("[  PASSED  ]");
static const char * FAILED  =     RED("[  FAILED  ]");
static const char * FAILURE  =    RED("[  FAILURE ]");
static const char * UNPASSED  =   RED("[  UNPASSED]");




#endif


