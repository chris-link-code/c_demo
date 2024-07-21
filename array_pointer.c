/**
 * https://mp.weixin.qq.com/s/hf50GKlu6HYwKf3OfITmWA
 * 函数指针数组
 *
 * 函数指针数组是指一个数组，其中的每个元素都是一个函数指针
 * 这种数组可以用于实现一个分派表，根据输入参数的不同，动态地调用不同的函数
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

void arr_arg(char arr[]) {
    // 当数组作为参数时，编译器会把它当作指针
    // 此处arr不再是数组，而是指针
    printf("%lu, sizeof arr\n", sizeof(arr));
}

typedef void (*operation_func_t)(int, int);

/**
 * 在上面的代码中，我们定义了四个函数 add、subtract、multiply 和 divide，
 * 分别对两个整数进行加、减、乘和除操作。
 * 然后，我们定义了一个函数指针类型 operation_func_t，
 * 它指向一个接受两个整型参数并没有返回值的函数。
 * 接着，我们定义了一个函数指针数组 operations，
 * 其中的每个元素都是一个 operation_func_t 类型的函数指针，
 * 分别指向 add、subtract、multiply 和 divide 函数。
 * 在 main 函数中，我们使用 for 循环遍历 operations 数组，
 * 并依次调用每个函数指针所指向的函数
 * 在每次调用函数之前，我们可以根据需要设置 a 和 b 的值
 * 这样，我们就可以动态地选择要执行的操作
 */
int main() {
    operation_func_t operations[] = {add, subtract, multiply, divide};
    size_t num_operations = sizeof(operations) / sizeof(operation_func_t);
    int a = 10, b = 5;
    for (size_t i = 0; i < num_operations; i++) {
        operations[i](a, b);
    }

    printf("--------------------------------------------------\n");

    // TODO 定义数组时 arr[] 和 arr[5] 的区别？
    int arr[5] = {1, 2, 3, 4, 5};
    int *p_1 = arr;

    // 数组名本身就是地址，是数组第一个元素的地址，因此这几个是等价的
    printf("value is %d，address is %p, p_1\n", *p_1, p_1);
    printf("value is %d，address is %p, p_1[0]\n", p_1[0], &p_1[0]);
    printf("value is %d，address is %p, arr\n", *arr, arr);
    printf("value is %d，address is %p, arr[0]\n", arr[0], &arr[0]);

    printf("address is %p, value is %d，p_1\n", p_1, *p_1);
    printf("address is %p, value is %d，p_1[0]\n", &p_1[0], p_1[0]);
    printf("address is %p, value is %d，arr\n", arr, *arr);
    printf("address is %p, value is %d，arr[0]\n", &arr[0], arr[0]);

    printf("--------------------------------------------------\n");

    // p_1是整型指针，p_2是数组指针
    // 虽然p_1和p_2的地址相同，但它们指向的的东西不同
    // p_1指向数组的第一个元素，p_2指向数组
    int (*p_2)[5] = &arr;
    printf("address is %p, value is %d，p_2\n", p_2, *p_2);

    // p_1 + 1，地址会增加4个字节
    // p_2 + 1，地址会增加20个字节
    printf("address is %p, value is %d，p_1 + 1\n", p_1 + 1, *(p_1 + 1));
    printf("address is %p, value is %d，p_2 + 1\n", p_2 + 1, *(p_2 + 1));

    // https://www.bilibili.com/video/BV1Tz421i7xZ/
    // 很多时候，数组和指针可以互相表示
    // 但在使用sizeof时要严格区分数组和指针
    // 指针和数组类型完全不一样
    char arr_1[] = "hello";
    char *p_3 = "hello";
    printf("%lu, sizeof arr_1\n", sizeof(arr_1));
    printf("%lu, sizeof p_3\n", sizeof(p_3));
    arr_arg(arr_1);

    return 0;
}