#pragma once
#include <stdint.h>
typedef struct stack_node_struct {
    char c;
    struct stack_node_struct *next;
} stack_node;

typedef struct stack_struct {
    stack_node *head;
    stack_node *tail;
    size_t size;
} stack;

stack *stack_create();
void stack_push(stack *stack, char c);
void stack_print_as_string(stack *stack);
void stack_pop(stack *stack);