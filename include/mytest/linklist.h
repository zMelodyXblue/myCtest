/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: Thu 22 Feb 2024 01:50:49 PM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

//根据T类型变量的成员的地址 addr 及名称 member 获得该T类型变量的起始地址
#define STARTADDR(addr, T, member) ((T*)(((char*)addr) - OFFSET(T, member)))
#define OFFSET(T, member) ((size_t)(&(((T*)(0))->member)))

struct LinkNode {
    struct LinkNode *next;
};

#endif
