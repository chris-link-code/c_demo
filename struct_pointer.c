//
// Created by chris on 2023/9/10.
// https://www.bilibili.com/video/BV1dh4y1P7j5/
//
#include <stdio.h>
#include <stdlib.h>

typedef struct USER {
    char *name;
    int age;
    int height;
    int health;
} User;

void print_user(User *user) {
    if (user) {
        printf("User name is %s, age is %d, height is %d, health is %d\n",
               user->name,
               user->age,
               user->height,
               user->health);
    }
}

// 必须手动释放申请的空间，否则会造成内存泄漏
void safe_free(void *p) {
    if (p) {
        free(p);
        p = NULL;
    }
}

/*
User create_user(char *name, int age, int height) {
    User user;
    user.name = name;
    user.age = age;
    user.height = height;
    user.health = age * 2 + height * 3;
    // 调用该方法接收到的user不再是前面声明的user
    // 因为这是栈空间，只在方法内有效，调用完成后自动回收
    // 实际返回时，会把这些变量复制到寄存器中，再从寄存器中把变量复制出来
    return user;
}
*/

User *create_user(char *name, int age, int height) {
    User *user = malloc(sizeof(User));
    user->name = name;
    user->age = age;
    user->height = height;
    user->health = age * 2 + height * 3;
    // 手动申请的空间为堆空间，方法调用完成后不回收
    return user;
}

int main() {
    User *u_1 = create_user("Frank", 12, 156);
    User *u_2 = create_user("Tom", 11, 160);
    User *u_3 = create_user("Jerry", 10, 161);

    print_user(u_1);
    print_user(u_2);
    print_user(u_3);

    safe_free(u_1);
    safe_free(u_2);
    safe_free(u_3);

    printf("--------------------------------------------------\n");

    // 初始化结构体
    // 指定字段初始化
    User u_4 = {.name = "Lily", .age = 19, .height = 169, .health = 517};
    print_user(&u_4);

    // 按顺序初始化
    User u_5 = {"Jack", 16, 186, .health = 523};
    print_user(&u_5);

    // 使用calloc初始化，所有字段被初始化为0
    User *u_6 = (User *) calloc(1, sizeof(User));
    print_user(u_6);
    safe_free(u_6);

    printf("--------------------------------------------------\n");

    printf("%lu, sizeof u_5\n", sizeof(u_5));
    printf("%lu, sizeof u_6\n", sizeof(u_6));

    return 0;
}