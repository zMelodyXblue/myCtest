/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Feb 2024 12:04:57 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define NONE  "\e[0m"      //清除颜色，即之后的打印为正常输出，之前的不受影响
#define BLACK  "\e[0;30m"  //深黑
#define L_BLACK  "\e[1;30m" //亮黑，偏灰褐
#define RED   "\e[0;31m" //深红，暗红
#define L_RED  "\e[1;31m" //鲜红
#define GREEN  "\e[0;32m" //深绿，暗绿
#define L_GREEN   "\e[1;32m" //鲜绿
#define BROWN "\e[0;33m" //深黄，暗黄
#define YELLOW "\e[1;33m" //鲜黄
#define BLUE "\e[0;34m" //深蓝，暗蓝
#define L_BLUE "\e[1;34m" //亮蓝，偏白灰
#define PINK "\e[0;35m" //深粉，暗粉，偏暗紫
#define L_PINK "\e[1;35m" //亮粉，偏白灰

#include <mytest/linklist.h>

#define TEST(a, b) \
void a##_test_##b(); \
__attribute__((constructor)) \
void add##_test_##a##_test_##b() { \
    add_function(a##_test_##b, #a"."#b); \
} \
void a##_test_##b()


#define TYPE_STR(a) _Generic((a), \
    int : "%d", \
    double : "%lf", \
    float : "%f", \
    long long : "%lld", \
    long : "%ld" \
)

#define P(a) { \
    char frm[10]; \
    sprintf(frm, "%s", TYPE_STR(a)); \
    printf(frm, a); \
}


#define EXPECT(a, b, comp) { \
    __typeof(a) _a = (a); \
    __typeof(b) _b = (b); \
    ++test_info.total; \
    if ((_a) comp (_b)) { \
        printf(L_GREEN"[-----------]" NONE " "#a" "#comp" "#b); \
        printf(GREEN" TRUE" NONE"\n"); \
        ++test_info.success; \
    } \
    else { \
        printf("\n" YELLOW); \
        printf("\t%s:%d: Failure\n", __FILE__,  __LINE__); \
        printf("\t\texpect %s %s %s actual : ", #a, #comp, #b); \
        P(_a); \
        printf(" vs "); \
        P(_b); \
        printf(NONE"\n\n"); \
        printf(L_GREEN"[-----------]" NONE " "#a" "#comp" "#b); \
        printf(L_RED" FALSE" NONE"\n"); \
    } \
}


#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)

typedef void (*TestFuncT)();

struct Function {
    TestFuncT run;
    const char *str;
    struct LinkNode p;  //链表骨架
};


struct FunctionInfo {
    int total, success;  //一个测试宏的判断总数和成功数
};

extern struct FunctionInfo test_info;

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *); //将测试宏（实为函数）加入到链表中

#endif
