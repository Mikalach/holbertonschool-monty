#include "main.h"

/**
 * push - f° that add a node to the stack
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: void value
 */
void push(stack_t **h, __attribute((unused))unsigned int l)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(37);
	}

	new->prev = NULL;

	if (*h == NULL)
	{
		new->next = NULL;
	}
	else
	{
		(*h)->prev = new;
		new->next = *h;
	}
	*h = new;
}
/**
 * pall - f° that print all values in the stack
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: void value
 */
void pall(stack_t **h, __attribute__((unused))unsigned int l)
{
	stack_t *temp = *h;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - f° that print the value in head
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: void value
 */
void pint(stack_t **h, unsigned int l)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l);
		error = 1;
		return;
	}
	printf("%d\n", (*h)->n);
}
/**
 * pop - f° that pop the head node of the stack
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: void value
 */
void pop(stack_t **h, unsigned int l)
{
	stack_t *temp = *h;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l);
		error = 1;
		return;
	}
	*h = (*h)->next;
	free(temp);

}
/**
 * swap - f° that swap the 2 most recent nodes on stack
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: void value
 */
void swap(stack_t **h, unsigned int l)
{
	stack_t *temp;
	int x;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l);
		error = 1;
		return;
	}
	temp = (*h)->next;
	x = (*h)->n;
	(*h)->n = temp->n;
	temp->n = x;

}
