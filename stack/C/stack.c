#include <stack.h>

const size_t INITIAL_CAPACITY = 128;

struct __Stack
{
    void **items;
    size_t length;
    size_t capacity;
};

Stack *Stack_new()
{
    Stack *self = malloc(sizeof(Stack));
    self->items = malloc(sizeof(void *) * INITIAL_CAPACITY);
    self->capacity = INITIAL_CAPACITY;
    self->length = 0;
    return self;
}
void Stack_free(Stack *self)
{
    if (!self)
    {
        fprintf(stderr, "Stack is not init");
        abort();
    }
    free(self->items);
    free(self);
}
void Stack_push(Stack *self, void *value)
{
    if (!self)
    {
        fprintf(stderr, "Stack is not init");
        abort();
    }
    if (self->length == self->capacity)
    {
        self->capacity *= 2;
        self->items = realloc(self->items, sizeof(void *) * self->capacity);
    }
    self->items[self->length++] = value;
}
void *Stack_pick(Stack *self)
{
    if (!self)
    {
        fprintf(stderr, "Stack is not init");
        abort();
    }
    if (Stack_isEmply(self))
    {
        return NULL;
    }
    return self->items[self->length - 1];
}
void *Stack_pop(Stack *self)
{
    if (!self)
    {
        fprintf(stderr, "Stack is not init");
        abort();
    }
    if (Stack_isEmply(self))
    {
        return NULL;
    }
    return self->items[self->length--];
}
bool Stack_isEmply(Stack *self)
{
    if (!self)
    {
        fprintf(stderr, "Stack is not init");
        abort();
    }
    return self->length ? true : false;
}