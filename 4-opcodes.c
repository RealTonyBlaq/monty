#include "monty.h"

/**
 * mul - function that multiplies the second top
 * element of the stack with the top element of the stack.
 * The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 * @head: pointer to the first node
 * @line_number: file line number
 * Return: Nothing
 */
void mul(stack_t **head, unsigned int line_number)
{
	int a, b, mult;
	stack_t *current;

	current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_arguments_node();
		exit(EXIT_FAILURE);
	}
	else
	{
		a = current->n;
		b = current->next->n;
		mult = a * b;
		current->next->n = mult;

		*head = current->next;
		current->next->prev = NULL;
		free(current);
	}
}

/**
 * stack - a function that set format for stack
 * @head: a pointer to pointer to first node
 * @line_number: file line number
 * Return: Nothing
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	arguments->stack_queue_switch = 1;
}

/**
 * queue - a function that set format for queue
 * @head: a poiter to the pointer to the first node
 * @line_number: file line number
 * Return: Nothing
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	arguments->stack_queue_switch = 0;
}

/**
 * nop - do nothing
 * @head: pointer to the first node of the stack
 * @line_number: current line number in file
 * Return: Nothing
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * rotr - Rotates the stack to the bottom; that means
 * the last element becomes the top element
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head, *temp = *head;
	int arr[50] = {0}, i = 0;
	(void)line_number;

	if (*head == NULL || current->next == NULL)
		return;
	while (temp != NULL)
	{
		arr[i] = temp->n;
		temp = temp->next;
		i++;
	}
	i -= 1;
	while (current != NULL && i >= 0)
	{
		current->n = arr[i];
		current = current->next;
		i--;
	}
}
