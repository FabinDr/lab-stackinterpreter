#ifndef stack_h
#define stack_h

typedef struct stack Stack;

Stack* new_stack(int size);
void free_stack(Stack* stack);
void stack_push(Stack* stack, int value);
int stack_pop (Stack* stack);
void stack_print(Stack* stack);

#endif
