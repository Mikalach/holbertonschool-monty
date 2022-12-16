#include "monty.h"

/**
 *open_file - open the given file
 *@file_name: name of the file to open
 */

void open_fd(char *file_name)
{
	FILE *fd = fopen(file_name, "r");
	/*if (file_name == NULL || fd == NULL)
	  error(2, file_name);*/
	read_fd(fd);
	fclose(fd);
	free_stack(head);
}

/**
 * read_file - read the given file previously opened
 * @fd: file descriptor
 */

void read_fd(FILE *fd)
{
	int line_number;
	char *line = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&line, &len, fd) != -1; line_number++)
	{
		tokenl(line, line_number);
	}

	free(line);
}

void tokenl(char *line, int line_number)
{
	char *opcode, *value;

	/*if (line == NULL)
	  error*/
	opcode = strtok(line, DELIM);
	if (opcode != NULL)
	{
		value = strtok(NULL, DELIM);
		get_func(opcode, value, line_number);
	}
}

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
