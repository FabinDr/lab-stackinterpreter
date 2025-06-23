#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *values;
    int capacity;
    int top;
};

Stack *new_stack(int size) {
    Stack *stack  = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;
    s->values = (int *)malloc(size * sizeof(int));
    if (!s->values) {
        free(stack);
        return NULL;
    }
    s->top = -1;
    s->capacity = size;
    return stack;
}

void free_stack(Stack* s) {
    if (s != NULL) {
        free(s->values);
        free(s);
    }
}

void stack_push(Stack *s, int value) {
    if (s->top >= s->capacity - 1) {
        printf("Erro: Pilha cheia (stack overflow)!\n");
        return;
    }
    s->values[++s->top] = value;
}

int stack_pop(Stack *s) {
    if (s->top < 0) {
        return -1; // Retorna -1 para sinalizar erro (pilha vazia)
    }
    return s->values[(s->top)--];
}

void stack_print(Stack *s) {
    if (s->top < 0) {
        printf("Pilha: [ Vazia ]\n");
        return;
    }
    printf("Pilha: [ ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->values[i]);
    }
    printf("] <- topo\n");
}
