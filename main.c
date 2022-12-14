#include "main.h"

unsigned int error;

/**
 * main - monty main function
 * @ac: num of args
 * @av: args array
 *
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av)
{
	FILE *fd;

	error = 0;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	if (_read(fd) == EXIT_FAILURE)
	{
		fclose(fd);
		return (EXIT_FAILURE);
	}
	fclose(fd);
	return (EXIT_SUCCESS);
}

/**
 * _read - f° to read a file
 * @fd: pointer FILE
 *
 * Return: 0 on success, 1 on failure
 */
int _read(FILE *fd)
{
	stack_t *head = NULL;
	char *buff = NULL;
	size_t buffsize = 1024;
	ssize_t n_read;
	unsigned int l = 0;

	n_read = getline(&buff, &buffsize, fd);
	while (n_read != -1)
	{
		l++;
		_line(buff, &head, l);
		if (error == 1)
		{
			if (buff != NULL)
				free(buff);
			buff = NULL;
			free_stack(head);
			return (EXIT_FAILURE);
		}
	}

	if (buff != NULL)
		free(buff);
	free_stack(head);
	return (EXIT_SUCCESS);
}

/**
 * _line - f° that cut a line from getline
 * @buff: line from getline
 * @h: pointer to head of the stack
 * @l: number of the line
 *
 * Return: 0 on success, 1 on failure
 */
int _line(char *buff, stack_t **h, unsigned int l)
{
	char *token;
	void (*f)(stack_t **stack, unsigned int line_number);
	unsigned int i = 0;

	token = strtok(buff, " \t\n");
	if (token == NULL)
	{
		return (EXIT_SUCCESS);
	}

	f = get_op(token);
	if (f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l, token);
		error = 1;
		return (EXIT_FAILURE);
	}

	f(h, l);

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \t\n");
		do {
			if (token && (isdigit(token[i]) || token[i] == ' '))
				i++;
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", l);
				error = 1;
				return (EXIT_FAILURE);
			}
		} while (token[i]);
		(*h)->n = atoi(token);
	}
	return (EXIT_SUCCESS);
}

/**
 * get_op - f° to get opcode function
 * @str: opcode command
 *
 * Return: function pointer
 */
void (*get_op(char *str))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (ops[i].opcode && strcmp(str, ops[i].opcode) != 0)
		i++;
	if (ops[i].opcode == NULL)
		return (NULL);
	return (ops[i].f);
}

/**
 * free_stack - f° that frees the stack
 * @h: pointer to head of the stack
 *
 * Return: void value
 */
void free_stack(stack_t *h)
{
	stack_t *temp = h;

	if (temp == NULL)
		return;

	while (h)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
	free(h);
}
