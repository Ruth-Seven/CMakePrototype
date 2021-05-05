
#include <cstdio>
#include "jtest.hpp"

// 全局共享添加的测试信息，其他文件引用应该加 external
FuncInfo funcinfo;

void add_funcdata(void (*func)(), char *funcname){
    funcinfo.add(func, funcname);
}


int testflag = 1; //
int RUN_ALL_TESTS()
{
    while(funcinfo.hasNext()){
        auto info = funcinfo.visit();
        auto func = info.first;
        auto funcname = info.second;
        printf("%s %s\n", RUN, funcname);
        testflag = 1;
        long long b = clock();
        func();
        long long e = clock();
        const char *p = nullptr;
        if(testflag) p = OK;
        else p = UNPASSED;
        printf("%s %s(%lld ms)\n", p, funcname, 
            1000 * (e - b) / CLOCKS_PER_SEC);
    }
    return 0;
}


// FuncData
FuncData::FuncData(void (*func)(), char* name):func(func), funcname(name){
    next = nullptr;
}

FuncData::~FuncData(){
    delete funcname;
}

//FuncInfo实现
FuncInfo::FuncInfo(): head(new FuncData(nullptr, nullptr)), tailp(head), now(head), curtest(0){}

void FuncInfo::add(void (*func)(), char *name){
    FuncData* p = new FuncData(func, name);
    tailp->next = p;
    tailp = p;
    ++curtest;
}


bool FuncInfo::hasNext(){
    return now->next;
}


std::pair<void (*)(), char *> 
FuncInfo::visit(){  
    if(hasNext()){
        now = now->next;
        return {now->func, now->funcname};
    }
    return {nullptr, nullptr};
}


FuncInfo::~FuncInfo(){
    FuncData *p = head->next;
    while(p){
        FuncData *newp = p->next;
        delete p;
        p = newp;
    }
}