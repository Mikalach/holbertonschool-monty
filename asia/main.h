#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern unsigned int error;

int _line(char *line, stack_t **h, unsigned int l);
int _read(FILE *fd);

void push(stack_t **h, unsigned int l);
void pall(stack_t **h, unsigned int l);
void pint(stack_t **h, unsigned int l);
void pop(stack_t **h, unsigned int l);
void swap(stack_t **h, unsigned int l);
void add(stack_t **h, unsigned int l);
void nop(stack_t **h, unsigned int l);

void (*get_op(char *str))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *h);

#endif
