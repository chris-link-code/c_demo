// 2023/12/1.
// https://github.com/sanxiadaba/c_data_structure
// C语言实现简单的链表（增删改查）

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct LIST_NODE {
    int data;
    struct LIST_NODE *next_node;
} list_node;

list_node *create_list_node(int data) {
    list_node *node = malloc(sizeof(list_node));
    node->data = data;
    node->next_node = NULL;
    return node;
}

void print_all_list_node(list_node *head) {
    list_node *now_node = head->next_node;
    while (now_node != NULL) {
        printf("%d\n", now_node->data);
        now_node = now_node->next_node;
    }
}

void free_all_list_node(list_node *node) {
    list_node *next_node = node->next_node;
    while (node != NULL) {
        free(node);
        node = next_node;
        if (next_node != NULL) {
            next_node = next_node->next_node;
        }
    }
}

void delete_list_node(list_node *head, int index) {
    assert(index > 0 && index <= (head->data));
    head->data = (head->data) - 1;
    list_node *before_node = head;
    list_node *now_node = head;
    for (int i = 0; i < index; i++) {
        before_node = now_node;
        now_node = now_node->next_node;
    }
    before_node->next_node = now_node->next_node;
    free(now_node);
}

int query_list_node(list_node *head, int index) {
    assert(index > 0 && index <= (head->data));
    list_node *now_node = head;
    for (int i = 0; i < index; i++) {
        now_node = now_node->next_node;
    }
    return now_node->data;
}

void modify_list_node(list_node *head, int index, int data) {
    assert(index > 0 && index <= (head->data));
    list_node *now_node = head;
    for (int i = 0; i < index; i++) {
        now_node = now_node->next_node;
    }
    now_node->data = data;
}

void insert_list_node(list_node *head, int index, int data) {
    list_node *new_node = create_list_node(data);
    head->data = (head->data) + 1;
    list_node *now_node = head;
    list_node *next_node = head->next_node;
    for (int i = 0; i < index; i++) {
        now_node = next_node;
        next_node = next_node->next_node;
    }
    now_node->next_node = new_node;
    new_node->next_node = next_node;
}

int main(void) {
    list_node *head = create_list_node(0);
    list_node *l1 = create_list_node(1);
    list_node *l2 = create_list_node(2);
    list_node *l3 = create_list_node(3);
    list_node *l4 = create_list_node(4);
    list_node *l5 = create_list_node(5);
    head->next_node = l1;
    l1->next_node = l2;
    l2->next_node = l3;
    l3->next_node = l4;
    l4->next_node = l5;
    head->data = 5;

    delete_list_node(head, 1);
    delete_list_node(head, 3);

    modify_list_node(head, 2, 100);
    printf("%d\n", query_list_node(head, 2));
    printf("==============\n");

    insert_list_node(head, 0, -100);
    insert_list_node(head, head->data, 900);

    print_all_list_node(head);
    free_all_list_node(head);
    return 0;
}