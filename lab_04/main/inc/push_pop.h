#ifndef _PUSH_POP_H_
#define _PUSH_POP_H_

int push_array_stack(array_stack_t *array_stack, char value);
int pop_array_stack(array_stack_t *array_stack, char *el);
int push_list_stack(list_stack_t **head_list, char value);
int pop_list_stack(list_stack_t **head_list);

#endif
