#include "monty.h"
stack_t *head = NULL;

/**
 *new_node - create a new node
 *@n: number to add
 *Return: pointer to new node
 */

stack_t *new_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(37);
	}
	new->next = NULL;
	new->prev = NULL;
	new->n = n;

	return (new);
}


/**
 *_push - Push node to stack
 *@new_node: pointer tp the new node
 *@line_number: line number
 */

void _push(stack_t **new_node, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (!head)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 *_pop - removes the top element of the stack
 * @stack: pointer the stac
 * @line_number: line number
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
