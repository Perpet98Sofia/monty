#include "monty.h"

/**
* rotl - rotates the first element of the stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next) /* move the right pointer to the last node */
		right = right->next;
	right->next = left; /* a circle infinite linked list loop */
	left->prev = right;
	*stack = left->next; /* so we cut the link between the 0 and 1 element */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
* rotr - rotates the last node of a stack_t stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
