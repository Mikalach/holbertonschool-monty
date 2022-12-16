#include "monty.h"

/**
 *_pall - print all element in the stack
 *@stack: Pointer to stack
 *@line_number: line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	free(tmp);
}

/**
 *_pint - print the value at the top of the stack
 *@stack: Pointer to stack
 *@line_number: line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * add - f° that add the 2 top nodes of the stack
 * @stack: pointer to head of the stack
 * @line_number: number of the line
 *
 * Return: void value
 */
void add(stack_t **stack, unsigned int line_number)
{
	unsigned int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		return;
	}

	temp = (*stack)->next;
	sum = (*stack)->n + temp->n;
	temp->n = sum;
	_pop(stack, line_number);
}

/**
 *_nop - does nothing
 *@stack: ^pointer to stack
 *@line_number: line number
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 *_swap - swap the first two elements of the stack
 *@stack: pointer to stack
 *@line_number: Line number
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return;
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
