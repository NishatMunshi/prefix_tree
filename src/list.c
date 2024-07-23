#include "../include/list.h"
#include <assert.h>
#include <stdlib.h>

void list_push(list *list, prefix_tree_node *prefix_tree_node) {
    assert(list != NULL && "list is nullptr\n");
    list_node *new_node = calloc(1, sizeof(struct list_node_struct));
    new_node->prefix_tree_node = prefix_tree_node;

    new_node->next = list->head;
    list->head = new_node;

    list->size++;
}
