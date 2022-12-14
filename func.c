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
	/*if (stack == NULL)
	{
		printf("ERROR");
		return;
	}*/
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 *_pint - print the value at the top of the stack
 *@stack: Pointer to stack
 *@line_number: line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	/*if (stack == NULL || *stack == NULL)
	  ERROR*/
	printf("%d\n", (*stack)->n);
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
	(void) line_number;

	/*maybe a condition is missing for the error
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	Error*/
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
