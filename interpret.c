#include "interpret.h"
#include "lista.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static Stack* stack = NULL;
static List* l = NULL;

void iniciar() {
    stack = new_stack(100);
    l = new_list();
}

void finalizar() {
    free_stack(stack);
    free_list(l);
}

void interpret(const char* source) {
    char op[10];
    char arg[50] = {0};
    sscanf(source, "%9s %49s", op, arg);

    if (strcmp(op, "push") == 0) {
        int value;
        char *endptr;
        value = strtol(arg, &endptr, 10);

        if (strlen(arg) == 0) {
            printf("Uso: push <valor | nome_variavel>\n");
            return;
        }

        if (*endptr == '\0') { // Se strtol consumiu a string inteira, é um número.
            stack_push(stack, value);
        } else { // Senão, é um nome de variável.
            int found;
            int var_value = get_variable(l, arg, &found);
            if (found) {
                stack_push(stack, var_value);
            } else {
                printf("Erro: Variavel '%s' nao encontrada.\n", arg);
            }
        }
    } else if (strcmp(op, "pop") == 0) {
        if (arg[0] == '\0') {
             printf("Uso: pop <nome_variavel>\n");
             return;
        }
        int value_from_stack = stack_pop(stack);
        if (value_from_stack == -1 && stack ->top < 0) { // Confirma que o -1 é de pilha vazia
             printf("Erro: Pilha vazia, nao ha nada para 'pop'.\n");
        } else {
             set_variable(l, arg, value_from_stack);
        }
    } else if (strcmp(op, "add") == 0) {
        int v2 = stack_pop(stack);
        int v1 = stack_pop(stack);
        stack_push(stack, v1 + v2);
    } else if (strcmp(op, "div") == 0) {
        int v2 = stack_pop(stack);
        int v1 = stack_pop(stack);
        stack_push(stack, v1 - v2);
    } else if (strcmp(op, "print") == 0) {
        int val = stack_pop(stack);
        if (val == -1 && stack->top < 0) {
             printf("Erro: Pilha vazia, nao ha nada para 'print'.\n");
        } else {
             printf("Saida: %d\n", val);
        }
    } else if (strcmp(op, "vars") == 0) {
        print_variables(l);
    } else {
        printf("Erro: Comando desconhecido '%s'.\n", op);
    }
}
