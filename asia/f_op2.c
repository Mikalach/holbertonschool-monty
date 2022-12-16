#include "main.h"

/**
 * add - f° that add the 2 top nodes of the stack
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: void value
 */
void add(stack_t **h, unsigned int l)
{
	unsigned int sum;
	stack_t *temp;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		error = 1;
		return;
	}

	temp = (*h)->next;
	sum = (*h)->n + temp->n;
	temp->n = sum;
	pop(h, l);
}

/**
 * nop - f° that do nothing
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: void value
 */
void nop(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;
}
