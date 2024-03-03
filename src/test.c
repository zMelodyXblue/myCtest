#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mytest/test.h>
#include <mytest/linklist.h>
#include <math.h>

struct FunctionInfo test_info;
struct Function func_head, *func_tail = &func_head;

int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p; ) {
        struct Function *func = STARTADDR(p, struct Function, p);
        printf(L_GREEN"[====RUN====]" NONE" %s\n", func->str);
        test_info.total = test_info.success = 0;
        func->run();
        double rate = 100.0 * test_info.success / test_info.total;
        printf(L_GREEN"[  " NONE);
        if (fabs(rate - 100.0) < 1e-6) {
            printf(L_BLUE"%6.2lf%%" NONE, rate);
        } else {
            printf(L_RED"%6.2lf%%" NONE, rate);
        }
        printf(L_GREEN"  ]" NONE" total : %d   success : %d\n\n", 
              test_info.total, 
              test_info.success
        );
        p = p->next;
        free(func);
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    struct Function *temp = (struct Function *)calloc(1, sizeof(struct Function));
    temp->run = func;
    temp->str = strdup(str);
    func_tail->p.next = &temp->p;
    func_tail = temp;
    return ;
}
