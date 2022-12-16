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
		fprintf(stderr, "Error: Can't open file");
		exit(EXIT_FAILURE);
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

	/*if (!new_node || !(*new_node))
		error*/
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
	(void) line_number;

	/*if (stack == NULL || *stack == NULL)
		error*/

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
