#include <stdio.h>

void func(void) {
    static int i = 0;
    printf("                                   func called %d times.\r", ++i);
    func();
}

void main(void) {
    func();
    func();
    func();
}
