#include "monty.h"

/**
 * main - main function
 *@ac: Argc
 *@av: argv
 *Return: 0 on success and error on fail
 */

int main(int ac, char **av)
{
	stack_t *head = NULL;
	(void)head;

	if (ac != 2)
	{
		fprintf(stderr, "ERROR !\n");
		exit(EXIT_FAILURE);
	}
	open_fd(av[1]);

	return (0);
}
