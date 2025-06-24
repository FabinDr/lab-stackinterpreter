#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *new_stack(int size) {
    Stack *stack  = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->values = (int *)malloc(size * sizeof(int));
    if (!stack->values) {
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->capacity = size;
    return stack;
}

void free_stack(Stack* stack) {
    if (stack != NULL) {
        free(stack->values);
        free(stack);
    }
}

void stack_push(Stack *stack, int value) {
    if (stack->top >= stack->capacity - 1) {
        printf("Erro: Pilha cheia (stack overflow)!\n");
        return;
    }
    stack->values[++stack->top] = value;
}

int stack_pop(Stack *stack) {
    if (stack->top < 0) {
        return -1; // Retorna -1 para sinalizar erro (pilha vazia)
    }
    return stack->values[(stack->top)--];
}

void stack_print(Stack *stack) {
    if (stack->top < 0) {
        printf("Pilha: [ Vazia ]\n");
        return;
    }
    printf("Pilha: [ ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->values[i]);
    }
    printf("] <- topo\n");
}
