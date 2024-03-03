/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Feb 2024 01:32:47 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mytest/test.h>

double add(double a, double b) {
    return a + b;
}

TEST(testFunc, add) {
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_LT(add(5, 3), 9);
    EXPECT_GT(add(6, 7), 9);
}

TEST(testFunc, add2) {
    EXPECT_EQ(add(5, 3.5), 8.1);
    EXPECT_LE(add(5, 3), 9);
    EXPECT_GE(add(6, 7), 9);
}

TEST(test, Funcadd) {
    EXPECT_LT(add(10, 20), 30);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
