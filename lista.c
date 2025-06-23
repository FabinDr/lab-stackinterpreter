#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Variavel {
    char nome[50];
    int valor;
    struct Variavel* proximo;
} Variavel;

static Variavel* lista_de_variaveis = NULL;

void store_variavel(const char* nome, int valor) {
    Variavel* atual = lista_de_variaveis;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
    }

    Variavel* nova_var = malloc(sizeof(Variavel));
    if (nova_var == NULL) {
        fprintf(stderr, "ERRO: Falha ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    
    strncpy(nova_var->nome, nome, sizeof(nova_var->nome) - 1);
    nova_var->nome[sizeof(nova_var->nome) - 1] = '\0';

    nova_var->valor = valor;
    nova_var->proximo = lista_de_variaveis;
    lista_de_variaveis = nova_var;
}

Variavel* load_variavel(const char* nome) {
    Variavel* atual = lista_de_variaveis;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

int variavel_exist(const char* nome) {
    return load_variavel(nome) != NULL;
}

void print_all_variables() {
    Variavel* atual = lista_de_variaveis;
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

void free_all_variables() {
    Variavel* atual = lista_de_variaveis;
    Variavel* proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista_de_variaveis = NULL;
}
