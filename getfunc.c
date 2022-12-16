#include "monty.h"

/**
 *get_func - function tp get on cmp
 *@opcode: the command inside monty code
 *@value: argument of opcode
 *@line_number: line number inside the file
 */

typedef void (*op_func)(stack_t **, unsigned int);

void get_func(char *opcode, char *value, int line_number)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"add", add},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_number);
			flag = 0;
		}
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

void call_fun(op_func func, char *opcode, char *value, int line_number)

{
	stack_t *node;
	int flag = 1;
	int i;

	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			printf("ERROR VALUE\n");
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
		}
		node = new_node(atoi(value) * flag);
		if (!node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(37);
		}

		func(&node, line_number);
	}
	else
		func(&head, line_number);
}
