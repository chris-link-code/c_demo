/**
 * https://mp.weixin.qq.com/s/hf50GKlu6HYwKf3OfITmWA
 * 函数指针与回溯法
 *
 * 回溯法是一种求解一些组合优化问题的算法，它通常使用递归来实现。
 * 函数指针可以用于实现回溯法算法的一些关键部分。
 */

#include <stdio.h>

typedef void (*callback_func_t)(const int *, size_t);

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute(int *nums, size_t len, size_t depth, callback_func_t callback) {
    if (depth == len) {
        callback(nums, len);
        return;
    }
    for (size_t i = depth; i < len; i++) {
        swap(&nums[depth], &nums[i]);
        permute(nums, len, depth + 1, callback);
        swap(&nums[depth], &nums[i]);
    }
}

void print_array(const int *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * 回调函数是指在某个事件发生时被调用的函数。通常，回调函数是在某个库函数或框架函数中注册的，
 * 当某个条件满足时，库函数或框架函数会调用回调函数来执行相应的操作
 */
void handle_event(int event_type, void (*callback)(void)) {
    printf("event %d occurred\n", event_type);
    if (callback) {
        callback();
    }
}

void callback_fun() {
    printf("callback function called\n");
}

void callback_func() {
    printf("another callback function called\n");
}

/**
 * 在上面的代码中，我们定义了一个函数 permute，用于计算给定数组的排列。
 * 在 permute 函数中，我们使用递归来生成所有可能的排列，
 * 并使用函数指针 callback 来指定每当我们生成一个排列时应该调用的函数。
 * 在本例中，我们将 print_array 函数作为回调函数传递给了 permute 函数。
 * 这意味着每当 permute 函数生成一个排列时，它都会调用 print_array 函数来打印这个排列。
 * 在 main 函数中，我们定义了一个包含三个整数的数组 nums，并使用 permute 函数来计算这个数组的所有排列。
 * 在每次生成一个排列时，permute 函数都会调用 print_array 函数来打印这个排列。
 */
int main() {
    int nums[] = {1, 2, 3};
    permute(nums, sizeof(nums) / sizeof(int), 0, print_array);

// TODO C语言回调函数
// https://blog.csdn.net/weixin_44127729/article/details/126415977
// https://mp.weixin.qq.com/s/hf50GKlu6HYwKf3OfITmWA

    /*
     * 
     * 回调函数
     *
     * 上面定义了一个 handle_event 函数，它接受两个参数：一个事件类型和一个函数指针。
     * 如果函数指针不为空，则会调用指定的函数。
     * 分别调用 handle_event 函数来触发两个事件，
     * 其中第一个事件注册了一个回调函数 callback_function，
     * 第二个事件没有注册回调函数
     */
    handle_event(0, NULL);
    handle_event(1, callback_fun);
    handle_event(2, callback_func);

    return 0;
}