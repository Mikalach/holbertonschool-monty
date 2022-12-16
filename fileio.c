#include "monty.h"

/**
 *open_file - open the given file
 *@file_name: name of the file to open
 */

void open_fd(char *file_name)
{
	FILE *fd = fopen(file_name, "r");
	if (fd == NULL)
		printf("ERROR 1");
	/*if (file_name == NULL || fd == NULL)
	  error(2, file_name);*/
	else
		read_fd(fd);
	if (fd != NULL)
		fclose(fd);
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
	ssize_t n_read = getline(&line, &len, fd);

	for (line_number = 1; n_read != -1; line_number++)
	{
		tokenl(line, line_number);
		return;
	}
	if (line != NULL)
	    free(line);
	free_stack(head);
}

void tokenl(char *line, int line_number)
{
	char *opcode, *value;

	/*if (line == NULL)
	  error*/
	opcode = strtok(line, DELIM);
	if (opcode == NULL)
		return;
	value = strtok(NULL, DELIM);
	get_func(opcode, value, line_number);
}

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
