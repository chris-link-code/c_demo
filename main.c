#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "md5.h"

/*����GBK��������*/

/*��õ�ǰʱ��ĺ���ֵ*/
long long current_timestamp() {
    struct timeval te;
    // get current time
    gettimeofday(&te, NULL);
    // calculate milliseconds
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

/*�����ڴ�й©*/
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
        //��ֵΪ�����ĵ�ַ
        p_arr[i] = &arr[i];
    }
    for (int i = 0; i < MAX; i++) {
        printf("Value of arr[%d] = %d, pointer is %d\n", i, *p_arr[i], p_arr[i]);
    }
}

/*��*/
void macro() {
    /**
        Ԥ�����
        ANSI C ���������ꡣ�ڱ����������ʹ����Щ�꣬���ǲ���ֱ���޸���ЩԤ����ĺꡣ
        __DATE__	��ǰ���ڣ�һ���� "MMM DD YYYY" ��ʽ��ʾ���ַ�������
        __TIME__	��ǰʱ�䣬һ���� "HH:MM:SS" ��ʽ��ʾ���ַ�������
        __FILE__	��������ǰ�ļ�����һ���ַ���������
        __LINE__	��������ǰ�кţ�һ��ʮ���Ƴ�����
        __STDC__	���������� ANSI ��׼����ʱ������Ϊ 1��
    */
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);
    printf("STDC_VERSION :%d\n", __STDC_VERSION__);
}

/*��ӡָ�����*/
void pointerPrint() {
    int value = 10;
    int *p;              // ����ָ�����
    p = &value;

    printf("value �����ĵ�ַ�� %p\n", p);
    printf("value ������ֵ�� %d\n", *p);
    printf("value ������ֵ�� %d\n", value);
}

/*�����ļ���MD5ֵ*/
void md5() {
    printf("\n================== MD5 Message-Digest Algorithm ==================\n\n");
    printf("[INPUT] Enter the filepath: ");

    printf("Time :%s\n", __TIME__);

    long start = current_timestamp();

    // �����ļ�·��
//    char filepath[256] = "/Users/chris/Movies/player.mkv";
    char filepath[256] = "C:/File/music/2U.mp3";
    //scanf("%s", filepath);

    // 128λ���
    uint8_t result[16];
    int i;

    // ����ֵ������1��ʾ�д���
    if (MD5(filepath, result) == 1) {
        printf("\n[INFO] The result is: ");

        //���ֽ�ͨ���޷���ʮ���������
        for (i = 0; i < 16; i++) {
            printf("%2.2x", result[i]);
        }
        printf("\n");
    }

    printf("Time :%s\n", __TIME__);
    long end = current_timestamp();
    printf("end %d", (end - start));
}

//����������
typedef _Bool bool;
#define true 1;
#define  false 0;

/*bool����*/
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
 * �����ַ���
 *
 * https://learn.microsoft.com/zh-cn/windows/win32/learnwin32/working-with-strings
 * ������һЩ�������ַ�����ص� typedefs���㽫������
 * Typedef	����
 * CHAR	char
 * PSTR �� LPSTR	char*
 * PCSTR �� LPCSTR	const char*
 * PWSTR �� LPWSTR	wchar_t*
 * PCWSTR �� LPCWSTR	const wchar_t*
 *
 * https://www.runoob.com/cprogramming/c-function-printf.html
 *
 * TEXT("x") �� _T("x")	L"x"	"x"
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
    printf("����̳�: %s\n", sites);
    printf("����̳�: %s\n", site);
    printf("����̳�: %s\n", s);


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
    //TODO ��bug
    printf("%s\n", str);*/
}

/*
 * GCC�кܶ���õ���չ
 * ���磺
 * int __builtin_types_compatible_p(type_a, type_b);
 * �����ж����������Ƿ���ͬ�����type_a�� type_b��ͬ�Ļ����ͻ᷵��1������Ļ�������0
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
 * __attribute__((constructor)) ����main()��������
 * __attribute__((destructor)) ��main()���������
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

//C����ʵ�ַ���
//typeof�ؼ�����GCC����
//https://www.bilibili.com/video/BV1zT411R7fN/
//��������δ�������͵ı�����ֵ
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
    // TODO �޷������ַ����飬��Ҫ��һ�����
    swap(*left, *right);

    printf("one: %d\n", one);
    printf("two: %d\n", two);
    printf("c: %c\n", c);
    printf("d: %c\n", d);

    printf("left: %s\n", left);
    printf("right: %s\n", right);

    printf("sum: %d\n", sum(one, two));
}

// ��ӡ�� i
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
    //value: Ҫת����������string: ת������ַ���,radix: ת������������2,8,10,16 ���Ƶȡ�
//    itoa(number1, string, 10);
    printf("���֣�%d ת������ַ���Ϊ��%s\n", number1, string);
//    itoa(number2, string, 10);
    printf("���֣�%d ת������ַ���Ϊ��%s\n", number2, string);
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
        // ���� m ~ n �������
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

// ���С��
// https://www.bilibili.com/video/BV1dC4y1i7i2/
void big_little() {
    int number = 0x12345678;
    char *p = &number;
    printf("0x%x\n", p[0]);
}

/**
 * argc: ����������
 * argv: ������ֵ
 */
int main(int argc, char *argv[]) {
    /*printf("main\n");
    printf("argc: %d\n", argc);

    if (argv != NULL) {
        // ������鳤��
        // ���ǣ���Ϊargv����ָ��ķ�ʽ���ݵ�
        // ���Ը÷�������õ���argv�ĳ�����ָ��ĳ��ȣ�Ҳ����1
        // ����ԭ��: sizeofֻ�Ǳ�����ָ�ֻ���жϡ�ԭʼ������Ĵ�С
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

