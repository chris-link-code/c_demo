/**
 * https://mp.weixin.qq.com/s/hf50GKlu6HYwKf3OfITmWA
 * 函数参数化
 *
 * 函数参数化是指通过函数指针将函数的某些行为参数化。
 * 这样，我们可以在调用函数时动态地指定函数的行为。
 */

#include <stdio.h>

void process_array(int *array, size_t size, int (*process)(int)) {
    for (size_t i = 0; i < size; i++) {
        array[i] = process(array[i]);
    }
}

int increment(int n) {
    return n + 1;
}

/**
 * 定义了一个 process_array 函数，它接受三个参数：一个整型数组、数组大小和一个函数指针。
 * 函数指针指向一个函数，该函数接受一个整型参数并返回一个整型结果。
 * 在 process_array 函数中，我们将数组中的每个元素传递给指定的函数，然后将函数的返回值存储回原数组中。
 * 在 main 函数中，定义了一个 increment 函数，它将传入的整数加 1。
 * 然后，我们调用 process_array 函数来处理整型数组，并打印出结果
 */
int main() {
    int array[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(array) / sizeof(int);
    process_array(array, size, increment);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}