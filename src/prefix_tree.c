#include "../include/prefix_tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
prefix_tree_node *prefix_tree_create() {
    return calloc(1, sizeof(prefix_tree_node));
}

prefix_tree_node *prefix_tree_has_child(prefix_tree_node const *root, char c) {
    assert(root != NULL && "root is nullptr\n");
    for (list_node *node = root->children.head; node != NULL; node = node->next) {
        if (node->prefix_tree_node->c == c) {
            return node->prefix_tree_node;
        }
    }

    return NULL;
}

void prefix_tree_insert(prefix_tree_node *root, char const *word) {
    assert(root != NULL && "root is nullptr\n");
    assert(word != NULL && "word is nullptr\n");
    if (word[0] == '\0') {
        return;
    }
    prefix_tree_node *node = prefix_tree_has_child(root, word[0]);
    if (!node) {
        node = prefix_tree_create();
        node->c = word[0];
        list_push(&root->children, node);
    }
    prefix_tree_insert(node, word + 1);
}

void prefix_tree_autocomplete(prefix_tree_node *root, char const *prefix, stack *stack) {
    assert(root != NULL && "root is nullptr\n");
    assert(prefix != NULL && "prefix is nullptr\n");
    assert(stack != NULL && "stack is nullptr\n");

    if (root->children.size == 0) {
        stack_print_as_string(stack);
        printf("\n");
        return;
    }
    if (prefix[0] == '\0') {
        for (list_node *list_node = root->children.head; list_node != NULL; list_node = list_node->next) {
            stack_push(stack, list_node->prefix_tree_node->c);
            prefix_tree_autocomplete(list_node->prefix_tree_node, "", stack);
            stack_pop(stack);
        }
        return;
    }
    prefix_tree_node *child = prefix_tree_has_child(root, prefix[0]);
    if (child) {
        stack_push(stack, child->c);
        prefix_tree_autocomplete(child, prefix + 1, stack);
        stack_pop(stack);
        return;
    }
    printf("prefix not found\n");
}
