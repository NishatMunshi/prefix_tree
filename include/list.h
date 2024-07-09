#pragma once
#include <stdint.h>
typedef struct prefix_tree_node_struct prefix_tree_node;
typedef struct list_node_struct {
    prefix_tree_node *prefix_tree_node;
    struct list_node_struct *next;
} list_node;

typedef struct list_struct {
    list_node *head;
    size_t size;
} list;

void list_push(list *list, prefix_tree_node *prefix_tree_node);