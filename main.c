#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "md5.h"

/*中文GBK不会乱码*/

/*获得当前时间的毫秒值*/
long long current_timestamp() {
    struct timeval te;
    // get current time
    gettimeofday(&te, NULL);
    // calculate milliseconds
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

/*测试内存泄漏*/
void memoryLeak() {
    int arr[] = {10, 100, 200};
    int MAX = 1 << 20;
    printf("Value of MAX = %d\n", MAX);
    for (int i = 0; i < MAX; i++) {
        //printf("Value of arr[%d] = %d\n", i, arr[i]);
        int *mem_pointer = NULL;
        mem_pointer = (int *) malloc(sizeof(int) * 128);
    }
    int *p_arr[MAX];

    for (int i = 0; i < MAX; i++) {
        p_arr[i] = (int *) malloc(sizeof(int) * MAX);
        //赋值为整数的地址
        p_arr[i] = &arr[i];
    }
    for (int i = 0; i < MAX; i++) {
        printf("Value of arr[%d] = %d, pointer is %d\n", i, *p_arr[i], p_arr[i]);
    }
}

/*宏*/
void macro() {
    /**
        预定义宏
        ANSI C 定义了许多宏。在编程中您可以使用这些宏，但是不能直接修改这些预定义的宏。
        __DATE__	当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
        __TIME__	当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
        __FILE__	这会包含当前文件名，一个字符串常量。
        __LINE__	这会包含当前行号，一个十进制常量。
        __STDC__	当编译器以 ANSI 标准编译时，则定义为 1。
    */
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);
    printf("STDC_VERSION :%d\n", __STDC_VERSION__);
}

/*打印指针变量*/
void pointerPrint() {
    int value = 10;
    int *p;              // 定义指针变量
    p = &value;

    printf("value 变量的地址： %p\n", p);
    printf("value 变量的值： %d\n", *p);
    printf("value 变量的值： %d\n", value);
}

/*计算文件的MD5值*/
void md5() {
    printf("\n================== MD5 Message-Digest Algorithm ==================\n\n");
    printf("[INPUT] Enter the filepath: ");

    printf("Time :%s\n", __TIME__);

    long start = current_timestamp();

    // 输入文件路径
//    char filepath[256] = "/Users/chris/Movies/player.mkv";
    char filepath[256] = "C:/File/music/2U.mp3";
    //scanf("%s", filepath);

    // 128位结果
    uint8_t result[16];
    int i;

    // 返回值不等于1表示有错误
    if (MD5(filepath, result) == 1) {
        printf("\n[INFO] The result is: ");

        //将字节通过无符号十六进制输出
        for (i = 0; i < 16; i++) {
            printf("%2.2x", result[i]);
        }
        printf("\n");
    }

    printf("Time :%s\n", __TIME__);
    long end = current_timestamp();
    printf("end %d", (end - start));
}

//类型重命名
typedef _Bool bool;
#define true 1;
#define  false 0;

/*bool测试*/
void boolTest() {
    bool bool_a = true;
    bool bool_b = false;
    bool bool_c = false;
    if (bool_a) {
        printf("This is true\n");
    }
    if (!bool_b) {
        printf("This is false\n");
    }

    printf("bool_c is %d\n", bool_c);
    bool_c = 1;
    printf("bool_c is %d\n", bool_c);
}

typedef wchar_t WCHAR;

/*
 * 测试字符串
 *
 * https://learn.microsoft.com/zh-cn/windows/win32/learnwin32/working-with-strings
 * 下面是一些其他与字符串相关的 typedefs，你将看到：
 * Typedef	定义
 * CHAR	char
 * PSTR 或 LPSTR	char*
 * PCSTR 或 LPCSTR	const char*
 * PWSTR 或 LPWSTR	wchar_t*
 * PCWSTR 或 LPCWSTR	const wchar_t*
 *
 * https://www.runoob.com/cprogramming/c-function-printf.html
 *
 * TEXT("x") 或 _T("x")	L"x"	"x"
 */
void stringTest() {
    char buf[1024] = {0};

    /*https://www.bilibili.com/video/BV1nM411a7Qe/*/
    char *c = "forest";
    printf("c: %s\n", c);

    /*https://www.runoob.com/cprogramming/c-strings.html*/
    char sites[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
    char site[] = "RUNOOB\0";
    char s[] = "RUNOOB";
    printf("菜鸟教程: %s\n", sites);
    printf("菜鸟教程: %s\n", site);
    printf("菜鸟教程: %s\n", s);


    //https://www.codersrc.com/archives/10406.html
    sprintf(buf, "www.codersrc.com\n");
    printf("%s", buf);

    sprintf(buf, "www.codersrc.com age:%d\n", 17);
    printf("%s", buf);

    sprintf(buf, "www.codersrc.com age:%d name:%s\n", 17, "zhangsan");
    printf("%s", buf);

    sprintf(buf, "www.codersrc.com age:%d name:%s height:%f\n", 17, "zhangsan", 1.75);
    printf("%s", buf);

    /*wchar_t a = L'a';
    wchar_t *str = L"hello";
    printf("%s\n", &a);
    //TODO 有bug
    printf("%s\n", str);*/
}

/*
 * GCC有很多好用的扩展
 * 比如：
 * int __builtin_types_compatible_p(type_a, type_b);
 * 用来判断两个类型是否相同，如果type_a与 type_b相同的话，就会返回1，否则的话，返回0
 * https://blog.csdn.net/akakakak250/article/details/64129401
 */
void compare_type() {
    int a = 3;
    int b = 9;
    char c = 'v';
    char d = 's';
    printf("a and b have same type: %d\n", __builtin_types_compatible_p(typeof(a), typeof(b)));
    printf("a and c have same type: %d\n", __builtin_types_compatible_p(typeof(a), typeof(c)));
    printf("c and d have same type: %d\n", __builtin_types_compatible_p(typeof(c), typeof(d)));
}

/*
 * __attribute__((constructor)) 先于main()函数调用
 * __attribute__((destructor)) 在main()函数后调用
 * https://blog.csdn.net/accumla/article/details/96161462
 */
static void before(void) __attribute__((constructor));

static void after(void) __attribute__((destructor));

static void before() {
    printf("before main\n");
}

static void after(void) {
    printf("after main\n");
}

//C语言实现泛型
//typeof关键字是GCC特有
//https://www.bilibili.com/video/BV1zT411R7fN/
//交换两个未定义类型的变量的值
#define swap(a, b) ({typeof(a) temp = a;a = b;b = temp;})
#define sum(a, b) (a + b)

void swap_value() {
    int one = 1;
    int two = 2;
    char c = 'c';
    char d = 'd';
    char left[] = "left";
    char right[] = "right";

    swap(one, two);
    swap(c, d);
    // TODO 无法交换字符数组，需要进一步解决
    swap(*left, *right);

    printf("one: %d\n", one);
    printf("two: %d\n", two);
    printf("c: %c\n", c);
    printf("d: %c\n", d);

    printf("left: %s\n", left);
    printf("right: %s\n", right);

    printf("sum: %d\n", sum(one, two));
}

// 打印出 i
// https://www.bilibili.com/video/BV1jh41177RH/
void double_pointer() {
    char *a[] = {"abc", "def", "hij"};
    char **p = a;
    printf("%c\n", *(char *) (a[2] + 1));
    printf("%c\n", *(a[2] + 1));
    printf("%c\n", a[2][1]);
    printf("%c\n", p[2][1]);
    printf("%c\n", *(*(p + 2) + 1));
}

// TODO sizeof
// TODO typeof

void int_to_string() {
    int number1 = 123456;
    int number2 = -123456;
    char string[sizeof(int)] = {0};
    //value: 要转换的整数，string: 转换后的字符串,radix: 转换进制数，如2,8,10,16 进制等。
//    itoa(number1, string, 10);
    printf("数字：%d 转换后的字符串为：%s\n", number1, string);
//    itoa(number2, string, 10);
    printf("数字：%d 转换后的字符串为：%s\n", number2, string);
}

void number() {
//    printf("INT_MAX: %d\n", INT_MAX);
//    printf("INT64_MAX: %d\n", INT64_MAX);
//    printf("LONG_MAX: %ld\n", LONG_MAX);
//    printf("LONG_LONG_MAX: %lld\n", LONG_LONG_MAX);

    long long one = 1;
    printf("1 << 32: %lld\n", one << 32);
}

void rand_number() {
    while (1) {
        // 生成 m ~ n 的随机数
        // int rand_number = rand() % (n - m + 1) + m;
        int rand_number = rand() % 4 + 1;

        printf("random 1 ~ 4: %d\n", rand_number);
        sleep(1);
    }
}

void length() {
    char *s = "string test";
    printf("strlen: %d\n", strlen(s));
    printf("sizeof: %d\n", sizeof(s));
}

void address() {
    char *p;
    char arr[] = {'v', 'c', 'g'};
    p = &arr;
    printf("arr address:\t %p\n", arr);
    printf("&arr address:\t %p\n", &arr);
    printf("&arr[0] address: %p\n", &arr[0]);
    printf("p address:\t %p\n", p);
    printf("arr[0] :\t %c\n", arr[0]);
}

// 大端小端
// https://www.bilibili.com/video/BV1dC4y1i7i2/
void big_little() {
    int number = 0x12345678;
    char *p = &number;
    printf("0x%x\n", p[0]);
}

/**
 * argc: 参数的数量
 * argv: 参数的值
 */
int main(int argc, char *argv[]) {
    /*printf("main\n");
    printf("argc: %d\n", argc);

    if (argv != NULL) {
        // 获得数组长度
        // 但是，因为argv是以指针的方式传递的
        // 所以该方法计算得到的argv的长度是指针的长度，也就是1
        // 根本原因: sizeof只是编译期指令，只能判断“原始”数组的大小
        int size = sizeof(*argv) / sizeof(argv[0]);
        printf("argv: %d\n", size);
        if (size > 0) {
            for (int i = 0; i < argc; ++i) {
                printf("argv[%d]: %s\n", i, argv[i]);
            }
        }
    } else {
        printf("argv is null");
    }*/



    //macro();
    //md5();
    //pointerPrint();
    //boolTest();
    //stringTest();
    //compare_type();
    //swap_value();
    //double_pointer();

//    int_to_string();
//    number();
//    rand_number();

//    length();
//    address();
    big_little();

    //system("pause");
    return 0;
}

