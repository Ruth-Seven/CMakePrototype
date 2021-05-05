
#ifndef JLOG_H

#define JLOG_H


// #define ISIGNORE_LOG // 禁止LOG功能	

#ifdef ISIGNORE_LOG

#define LOG(fmt, args...) {}

#else

#define LOG(fmt, args...) { \
    printf("[%s: %s]", __FILE__, __func__); \
    printf(fmt, ##args); \
    printf("\n"); \
}

#endif


#endif
