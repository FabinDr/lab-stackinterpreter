// lista.c

#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Variavel {
    char nome[50];
    int valor;
    struct Variavel* proximo;
} Variavel;

struct list {
    Variavel* head;
};

List* new_list() {
    List* l = malloc(sizeof(List));
    if (!l) return NULL;
    l->head = NULL;
    return l;
}

void free_list(List* l) {
    Variavel* atual = l->head;
    while (atual != NULL) {
        Variavel* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(l);
}

void set_variable(List* l, const char* nome, int valor) {
    Variavel* atual = l->head;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
    }
    Variavel* nova = malloc(sizeof(Variavel));
    strncpy(nova->nome, nome, sizeof(nova->nome) - 1);
    nova->nome[sizeof(nova->nome) - 1] = '\0';
    nova->valor = valor;
    nova->proximo = l->head;
    l->head = nova;
}

int get_variable(List* l, const char* nome, int* found) {
    Variavel* atual = l->head;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            *found = 1;
            return atual->valor;
        }
        atual = atual->proximo;
    }
    *found = 0;
    return -1;
}

void print_variables(List* l) {
    Variavel* atual = l->head;
    if (atual == NULL) {
        printf("Nenhuma variavel na memoria.\n");
        return;
    }
    printf("--- Memoria de Variaveis ---\n");
    while (atual != NULL) {
        printf("  %s -> %d\n", atual->nome, atual->valor);
        atual = atual->proximo;
    }
    printf("----------------------------\n");
}
