#include "../include/stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

stack *stack_create() {
    return calloc(1, sizeof(struct stack_struct));
}

void stack_push(stack *stack, char c) {
    assert(stack != NULL && "stack is nullptr\n");
    stack_node *new_node = calloc(1, sizeof(struct stack_node_struct));
    new_node->c = c;

    if (stack->head == NULL) {
        stack->head = new_node;
        stack->tail = new_node;
    } else {
        stack->tail->next = new_node;
        stack->tail = new_node;
    }

    stack->size++;
}

void stack_print_as_string(stack *stack) {
    assert(stack != NULL && "stack is nullptr\n");
    for (stack_node *node = stack->head; node != NULL; node = node->next) {
        printf("%c", node->c);
    }
}
void stack_pop(stack *stack) {
    assert(stack != NULL && "stack is nullptr\n");
    if (stack->size == 0) {
        return;
    }
    if (stack->size == 1) {
        free(stack->head);
        stack->head = stack->tail = NULL;
        stack->size = 0;
        return;
    }
    stack_node *stack_node = stack->head;
    for (size_t i = 0; i < stack->size - 1; ++i) {
        stack->tail = stack_node;
        stack_node = stack_node->next;
    }
    free(stack_node);
    stack->size--;
}
