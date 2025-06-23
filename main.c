#include "interpret.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT];
    
    iniciar(); // Inicializa a pilha e a lista

    printf("Maquina de Pilha Interativa. Digite 'quit' para sair.\n");

    while (1) {
        printf("> ");
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            break;
        }

        if (strlen(input) > 0) {
            interpret(input);
        }
    }

    finalizar(); // Libera toda a memória antes de sair
    printf("Programa encerrado.\n");
    return 0;
}
