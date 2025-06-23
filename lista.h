#ifndef LISTA_H
#define LISTA_H

typedef struct list List;

List* new_list();
void free_list(List* l);
void set_variable(List* l, const char* key, int value);
int get_variable(List* l, const char* key, int* found);
void print_variables(List* l);

#endif
