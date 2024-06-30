//
// Created by chris on 2024/6/24.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y);

void swap_p(int *x, int *y);

int *allocate_array(int size, int value);

int *allocate_array_p(int size, int value);

void allocate_array_pp(int *arr, int size, int value);

int square(int num);

void *p_3;

int main() {
    int a = 5;
    int *p_1 = &a;
    // %p 显示十六进制，不输出0x
    // %p 显示专用格式，通常是十六进制
    printf("a value is %d，address is %p\n", a, &a);
    printf("a value is %d，address is %p\n", *p_1, p_1);

    // 如果指针为NULL值，那就会被解释为二进制O
    if (p_1) {
        printf("p_1 is not null\n");
    }
    if (p_1 != NULL) {
        printf("p_1 is not null\n");
    }

    // 指针被声明为全局或静态，会在程序启动时被初始化为NULL
    // 指针被声明为局部，不会被初始化为NULL，且有地址
    void *p_2;
    if (p_2) {
        printf("p_2 is not null, value is 0x%p\n", p_2);
    }

    if (p_3 == NULL) {
        printf("p_3 is null\n");
    }

    static void *p_4;
    if (p_4 == NULL) {
        printf("p_4 is null\n");
    }

    // 指针用于存放地址，其大小由机器字长决定，32位机器是4字节的，64位机器是8字节的
    // 数据指针的长度通常是一样的，与指针类型无关，char指针和结构体指针长度相同
    // 不过，函数指针长度可能与数据指针长度不同

    /*
     * size_t
     * 无符号整数类型，它是sizeof关键字的结果
     * 用于安全地表示长度，表示任何对象所能达到的最大长度
     * 在声明诸如字符数或者数组索引这样的长度变量时用size_t是好的做法
     * 它经常用于循环计数器，数组索引，有时候还用在指针算术运算上
     * 一般来说，size_t可能的最大值是SIZE_MAX
     * size_t是无符号的，一定要给这种类型的变量赋正数
     * 打印size _t类型的值时要小心，这是无符号值，如果选错格式说明符，可能会得到不可靠的结果
     * 推荐的格式说明符是%zu。不过，某些情况下不能用这个说明符，作为替代，可以考虑%u或%lu
     */
    // 当需要用指针长度时，一定要用sizeof操作符
    int void_p_int = sizeof(void *);
    size_t void_p_size = sizeof(void *);
    size_t int_p_size = sizeof(int *);
    size_t char_p_size = sizeof(char *);
    size_t long_p_size = sizeof(long *);
    size_t double_p_size = sizeof(double *);
    printf("void* size is %d\n", void_p_int);
    printf("void* size is %d\n", void_p_size);
    printf("int* size is %d\n", int_p_size);
    printf("char* size is %d\n", char_p_size);
    printf("long* size is %d\n", long_p_size);
    printf("double* size is %d\n", double_p_size);

    /*
     * intptr_t和uintptr_t
     * intptr_t和uintptr_t类型用来存放指针地址
     * 它们提供了一种可移植且安全的方法声明指针，而且和系统中使用的指针长度相同
     * 对于把指针转化成整数形式来说很有用
     * uintptr_t是intptr_t的无符号版本，对于大部分操作，用intptr_t比较好
     * 当可移植性和安全性变得重要时，就应该使用这些类型
     */

    size_t void_size = sizeof(void);
    size_t char_size = sizeof(char);
    size_t short_size = sizeof(short);
    size_t int_size = sizeof(int);
    size_t long_size = sizeof(long);
    size_t float_size = sizeof(float);
    size_t double_size = sizeof(double);
    printf("void size is %d\n", void_size);
    printf("char size is %d\n", char_size);
    printf("short size is %d\n", short_size);
    printf("int size is %d\n", int_size);
    printf("long size is %d\n", long_size);
    printf("float size is %d\n", float_size);
    printf("double size is %d\n", double_size);

    char *word = "hello world";
    printf("%s\n", word);

    int b = 7;
    int c = 8;
    printf("b value is %d，address is %p\n", b, &b);
    printf("c value is %d，address is %p\n", c, &c);
    swap_p(&b, &c);
    printf("b value is %d，address is %p\n", b, &b);
    printf("c value is %d，address is %p\n", c, &c);

    int d = 9;
    int e = 10;
    printf("d value is %d，address is %p\n", d, &d);
    printf("e value is %d，address is %p\n", e, &e);
    swap(d, e);
    printf("d value is %d，address is %p\n", d, &d);
    printf("e value is %d，address is %p\n", e, &e);

    /*
     * 内存泄漏
     * 1. 丢失内存地址，当指针又指向第二次分配的内存时，第一次分配的内存的地址就会丢失
     * 2. 应该调用free函数却没有调用
     *
     * 在释放用struct关键字创建的结构体时也可能发生内存泄漏
     * 如果结构体包含指向动态分配的内存的指针，那么需要在释放结构体之前先释放这些指针
     */
    /*
     * 执行malloc函数时会进行以下操作:
     * (1)从堆上分配内存
     * (2)内存不会被修改或是清空
     * (3)返回首字节的地址
     */
    int *p_5 = (int *) malloc(sizeof(int));
    *p_5 = 5;
    printf("p_5 value is %d，address is %p\n", *p_5, p_5);
    if (p_5) {
        // 释放指针之前先判空，释放之后置为null是好习惯
        free(p_5);
        p_5 = NULL;
    }

    const int size = 5;
    const int value = 6;
    int *p_6 = allocate_array(size, value);
    for (int i = 0; i < size; i++) {
        printf("p_6 value is %d，address is %p\n", p_6[i], &p_6[i]);
    }

    int *p_7 = allocate_array_p(size, value);
    if (p_7) {
        for (int i = 0; i < size; i++) {
            printf("p_7 value is %d，address is %p\n", p_7[i], &p_7[i]);
        }
        free(p_7);
        p_7 = NULL;
    }

    /*
     * 运行后程序打印0，因为将p_8传递给函数时，它的值被复制到了参数arr中，修改arr对p_8没有影响
     * 当函数返回后，没有将存储在arr中的值复制到p_8中
     * 另外，还发生了内存泄漏，无法再访问allocate_array_pp函数中arr地址指向的内存块了
     */
    int *p_8 = NULL;
    allocate_array_pp(&p_8, size, value);
    printf("p_8 value is %d，address is %p\n", p_8, &p_8);
    if (p_8) {
        free(p_8);
        p_8 = NULL;
    }

    // 函数指针的用法
    // 定义一个函数指针p_9
    int (*p_9)(int);
    // 将square函数的地址赋值给p_9
    p_9 = square;
    int n = 5;
    // 使用函数指针调用函数
    printf("%d squared is %d\n", n, p_9(n));

    return 0;
}

// 通过值传递，交换失败
// 形参x、y中保存的只是实参d、e的副本，修改形参不会影响实参
void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 通过指针传递，交换成功，地址不变
void swap_p(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 把指针当数组用
/*
 * 尽管可以正确工作，但从函数返回指针时可能存在几个潜在的问题，包括:
 * • 返回未初始化的指针
 * • 返回指向无效地址的指针
 * • 返回局部变量的指针
 * • 返回指针但是没有释放内存
 */
int *allocate_array_p(int size, int value) {
    if (size < 1) return NULL;
    int *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
    return arr;
}

/*
 * 局部数据指针
 * 如果你不理解程序栈如何工作，就很容易犯返回指向局部数据的指针的错误
 * 一旦函数返回，返回的数组地址也就无效了，因函数的栈帧从栈中弹出了
 * 尽管每个数组元素仍然可能包含value，但如果调用另一个函数，就可能覆写这些值
 * 以这种方式创建并初始化数组是绝对不可取的！！！
*/
int *allocate_array(int size, int value) {
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
    return arr;
}

void allocate_array_pp(int *arr, int size, int value) {
    arr = (int *) malloc(size * sizeof(int));
    printf("arr value is %d，address is %p\n", *arr, arr);
    if (arr) {
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }
}

int square(int num) {
    return num * num;
}