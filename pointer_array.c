/*
 * https://mp.weixin.qq.com/s/hf50GKlu6HYwKf3OfITmWA
 * 函数指针数组
 *
 * 函数指针数组是指一个数组，其中的每个元素都是一个函数指针。
 * 这种数组可以用于实现一个分派表，根据输入参数的不同，动态地调用不同的函数。
 */


#include <stdio.h>

void add(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("%d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b) {
    printf("%d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b) {
    if (b == 0) {
        printf("cannot divide by zero\n");
    } else {
        printf("%d / %d = %d\n", a, b, a / b);
    }
}

typedef void (*operation_func_t)(int, int);

int main() {
    operation_func_t operations[] = {add, subtract, multiply, divide};
    size_t num_operations = sizeof(operations) / sizeof(operation_func_t);
    int a = 10, b = 5;
    for (size_t i = 0; i < num_operations; i++) {
        operations[i](a, b);
    }
    return 0;
}