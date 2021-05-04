
#include <cstdio>
#include "jtest.hpp"




void add_funcdata(void (*func)(), char *funcname){
    data.funcname[curtest] = funcname;
    data.funcarr[curtest++] = func;
}

void delete_funcdata(){
    for(int i = 0; i < curtest; i++){
        delete data.funcname[i];
    }
    curtest = 0; // 程序结束，无需再删除资源
}


int RUN_ALL_TESTS()
{
    for(int i = 0; i < curtest; ++i){
        printf("%s %s\n", RUN, data.funcname[i]);
        testflag = 1;
        long long b = clock();
        data.funcarr[i]();   
        long long e = clock();
        const char *p = nullptr;
        if(testflag) p = OK;
        else p = FAILED;
        printf("%s %s(%lld ms)\n", p, data.funcname[i], 
            1000 * (e - b) / CLOCKS_PER_SEC);
    }
    return 0;
}

