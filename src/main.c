#include "../include/prefix_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("USAGE: .\\main <prefix to search>\n");
        printf("    ERROR: no prefix provided\n");
        exit(1);
    }

    prefix_tree_node *tree = prefix_tree_create();
    prefix_tree_insert(tree, "apple");
    prefix_tree_insert(tree, "apricot");
    prefix_tree_insert(tree, "avocado");

    prefix_tree_autocomplete(tree, argv[1], stack_create());

    return 0;
}