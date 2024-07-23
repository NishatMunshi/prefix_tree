#pragma once
#include "list.h"
#include "stack.h"

struct prefix_tree_node_struct {
    char c;
    list children;
};

prefix_tree_node *prefix_tree_create();
void prefix_tree_insert(prefix_tree_node *root, char const *word);
void prefix_tree_autocomplete(prefix_tree_node *root, char const *prefix, stack *stack);