#include <stdio.h>

void changePointer(int **pp) {
    static int value = 100;
    *pp = &value;  // 修改一级指针的指向
}

int main() {
    int x = 10;
    int *p = &x;    // p指向x
    
    printf("修改前: p指向的值 = %d\n", *p);
    
    changePointer(&p);  // 传递指针p的地址
    
    printf("修改后: p指向的值 = %d\n", *p);
    return 0;
}