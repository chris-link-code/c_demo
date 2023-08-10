//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//全局未初始化区
char *p1;

// TODO 占用1G内存
int main() {
    printf("%d\n", (1 << 30));
    p1 = (char *) malloc((1 << 30) * sizeof(char));
    sleep(30);
    printf("free\n");
    free(p1);
    sleep(30);
    return 0;
}