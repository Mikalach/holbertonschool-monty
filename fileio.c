#include "monty.h"

/**
 *open_fd - open the given file
 *@file_name: name of the file to open
 */

void open_fd(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	read_fd(fd);
	fclose(fd);
	free_stack(head);
}

/**
 * read_fd - read the given file previously opened
 * @fd: file descriptor
 */

void read_fd(FILE *fd)
{
	int line_number;
	char *line = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&line, &len, fd) != -1; line_number++)
	{
		if (line[0] == '\n')
			continue;
		tokenl(line, line_number);
	}

	free(line);
}

/**
 * tokenl - function that tokenize line
 * @line: line to tokenize
 * @line_number: number of the line
*/
void tokenl(char *line, int line_number)
{
	char *opcode, *value;

	opcode = strtok(line, DELIM);
	if (opcode != NULL)
	{
		value = strtok(NULL, DELIM);
		get_func(opcode, value, line_number);
	}
}

/**
 * free_stack - function used to free the stack
 * @h: pointer to head of the stack
*/
void free_stack(stack_t *h)
{
	stack_t *temp = NULL;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
	free(h);
}
