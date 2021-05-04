
#ifndef JLOG_H

#define JLOG_H

#ifdef ISIGNORE_LOG

#define LOG(fmt, args..) {}

#else

#define LOG(fmt, args...) { \
    printf("[%s: %s]", __FILE__, __func__); \
    printf(fmt, ##args); \
    printf("\n"); \
}

#endif


#endif
