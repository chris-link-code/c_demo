#include <stdio.h>
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

/*bool����*/
void boolTest() {
    bool true = 1;
    bool false = 0;
    bool flag = 0;
    if (true) {
        printf("This is true\n");
    }
    if (!false) {
        printf("This is false\n");
    }

    printf("flag is %d\n", flag);
    flag = 1;
    printf("flag is %d\n", flag);
}

int main() {
    //macro();
    //md5();
    //pointerPrint();
    boolTest();

    //system("pause");
    return 0;
}

