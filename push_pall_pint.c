#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - prints the stack
 * @stack: stack given by main in start.c
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}

/**
 * pint - print the value at the top of the stack
 * @stack: stack given by main in start.c
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}
