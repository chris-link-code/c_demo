#include <stdio.h>

/**
 * https://mp.weixin.qq.com/s/hf50GKlu6HYwKf3OfITmWA
 * 函数参数化
 *
 * 函数参数化是指通过函数指针将函数的某些行为参数化。
 * 这样，我们可以在调用函数时动态地指定函数的行为。
 */

void process_array(int *array, size_t size, void (*process)(int *)) {
    for (size_t i = 0; i < size; i++) {
        process(&array[i]);
    }
}

void increment(int *n) {
    *n += 1;
}

int square(int num) {
    return num * num;
}

int main() {
    /**
     * 定义了一个 process_array 函数
     * 它接受三个参数：一个整型数组、数组大小和一个函数指针
     * 函数指针指向一个函数，该函数接受一个整型参数并返回一个整型结果
     * 在 process_array 函数中，我们将数组中的每个元素传递给指定的函数
     * 然后将函数的返回值存储回原数组中
     * 在 main 函数中，定义了一个 increment 函数，它将传入的整数加 1
     * 然后，我们调用 process_array 函数来处理整型数组，并打印出结果
     */
    int array[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(array) / sizeof(int);
    process_array(array, size, increment);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 函数指针的用法
    // 声明一个函数指针p
    // int (*p)(int);
    // 将square函数的地址赋值给p
    // p = square;
    // 也可以声明并同时赋值
    int (*p)(int) = square;
    // 函数名前的&写不写都行
    // int (*p)(int) = &square;
    int n = 5;
    // 使用函数指针调用函数
    // p(n) 和 (*p)(n) 这两种调用方法都可以
    // 推荐使用p(n)方式直接使用函数指针变量调用函数
    // 因为它避免了编译器的隐式转换，使得代码更加直接和高效
    printf("%d squared is %d\n", n, p(n));

    return 0;
}