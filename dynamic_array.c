// 2023/12/1.
// https://github.com/sanxiadaba/c_data_structure
// C语言实现简单的动态数组（类似C++的vector）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DYN_ARR {
    int *arr;
    int capacity;
    int size;
} dyn;

dyn init_dyn_arr(int arr[], int size) {
    int *tmp = malloc(sizeof(int) * size * 2);
    memcpy(tmp, arr, sizeof(int) * size);
    dyn my_arr;
    my_arr.arr = tmp;
    my_arr.size = size;
    my_arr.capacity = size * 2;
    return my_arr;
}

void print_dyn_arr(dyn my_arr) {
    for (int i = 0; i < my_arr.size; i++) {
        printf("%d ", my_arr.arr[i]);
    }
    printf("\n");
}

dyn insert_last_dyn_arr(dyn my_arr, int val) {
    int size = my_arr.size;
    int capacity = my_arr.capacity;
    if (size < capacity) {
        (my_arr.arr)[size] = val;
    } else {
        int *tmp = malloc(sizeof(int) * capacity * 2);
        memcpy(tmp, my_arr.arr, sizeof(int) * capacity);
        free(my_arr.arr);
        my_arr.arr = tmp;
        my_arr.capacity = capacity * 2;
        (my_arr.arr)[size] = val;
    }

    my_arr.size++;
    return my_arr;
}

dyn delete_last_dyn_arr(dyn my_arr) {
    my_arr.size--;
    return my_arr;
}

int query_dyn_arr(dyn my_arr, int index) {
    return (my_arr.arr)[index];
}

void modify_dyn_arr(dyn my_arr, int index, int val) {
    (my_arr.arr)[index] = val;
}

dyn insert_data_dyn_arr(dyn my_arr, int index, int val) {
    int size = my_arr.size;
    int capacity = my_arr.capacity;
    if (size < capacity) {
        memmove(my_arr.arr + index + 1, my_arr.arr + index, sizeof(int) * (size - index));
        (my_arr.arr)[index] = val;
    } else {
        int *tmp = malloc(sizeof(int) * capacity * 2);
        memcpy(tmp, my_arr.arr, sizeof(int) * capacity);
        free(my_arr.arr);
        my_arr.arr = tmp;
        my_arr.capacity = capacity * 2;
        (my_arr.arr)[index] = val;
    }

    my_arr.size++;
    return my_arr;
}

dyn delete_dyn_arr(dyn my_arr, int index) {
    memmove(my_arr.arr + index, my_arr.arr + index + 1, sizeof(int) * (my_arr.size - index - 1));
    my_arr.size--;
    return my_arr;
}

int main(void) {
    dyn my_arr = init_dyn_arr((int[]) {1, 2, 3, 4, 5}, 5);
    my_arr = insert_last_dyn_arr(my_arr, 100);
    my_arr = insert_last_dyn_arr(my_arr, 200);
    my_arr = insert_last_dyn_arr(my_arr, 300);
    my_arr = insert_last_dyn_arr(my_arr, 400);
    my_arr = insert_last_dyn_arr(my_arr, 500);
    my_arr = insert_last_dyn_arr(my_arr, 600);

    my_arr = delete_last_dyn_arr(my_arr);
    my_arr = delete_last_dyn_arr(my_arr);

    modify_dyn_arr(my_arr, 2, 890);
    my_arr = insert_data_dyn_arr(my_arr, 0, -897);
    my_arr = insert_data_dyn_arr(my_arr, 2, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, -9856);
    my_arr = insert_data_dyn_arr(my_arr, 0, 99999999);

    my_arr = delete_dyn_arr(my_arr, 0);
    my_arr = delete_dyn_arr(my_arr, 17);
    printf("第三个元素为 ：%d\n", query_dyn_arr(my_arr, 2));
    print_dyn_arr(my_arr);
    printf("现在容量为%d 储存%d元素\n", my_arr.capacity, my_arr.size);
    free(my_arr.arr);
    return 0;
}