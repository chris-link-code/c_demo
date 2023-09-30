//
// Created by chris on 2023/9/29.
// 文件读写
// https://www.bilibili.com/video/BV1qC4y1f7gZ/
//
#include <stdio.h>
#include <stdlib.h>

/*
 * ftell 统计文件指针移动的字节数
 * fseek 定位文件指针
 * int fteel(FILE* fp)
 * fseek(FILE* fp, long size, int mode)
 * mode:
 *  SEEK_CUR 当前位置
 *  SEEK_END 结束位置
 *  SEEK_SET 开始位置
 * feof(FILE* fp) 判断文件指针是否在文件末尾
 * rewind(FILE* fp) 把文件指针恢复到文件开始的位置
 * freopen() 把输入和输出定向为文件
 */

// 获取文件大小，字节数
int file_size(FILE *fp) {
    if (fp == NULL) {
        printf("file open failed");
        return 0;
    }
    // 文件移动到文件末尾
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    return size;
}

// 将文件复制到内存中
char *copy_to_memory(FILE *fp) {
    if (fp == NULL) {
        printf("file is null");
        return NULL;
    }
    int size = file_size(fp);
    printf("file size is %d\n", size);
    // size + 1 ，字符串结束标记
    char *file_memory_size = (char *) malloc(size + 1);
    fread(file_memory_size, size, 1, fp);
    return file_memory_size;
}

int main() {
    // 把文件重定向为标准输入
//    FILE *input = freopen("input.txt", "w", stdin);
    // 把标准输出重定向到文件
    FILE *output = freopen("info.log", "a", stdout);
//    printf("1\n");
//    printf("2\n");
//    printf("3\n");

    FILE *fp = fopen("D:\\temporary\\z.mp4", "r");
    char *file_memory = copy_to_memory(fp);

    // 在这里对文件进行操作

    free(file_memory);
    file_memory = NULL;

    //释放文件占用
    fclose(fp);
    fclose(output);
//    fclose(input);

    // 暂停程序
//    system("pause");
    return 0;
}