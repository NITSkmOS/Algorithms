#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __Stack Stack;

Stack *Stack_new();
void Stack_free(Stack *self);
void Stack_push(Stack *self, void *value);
void *Stack_pick(Stack *self);
void *Stack_pop(Stack *self);
bool Stack_isEmply(Stack *self);