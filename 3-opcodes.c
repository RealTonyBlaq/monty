#include "monty.h"

/**
 * mod - Finds the remainder of first two data on the stack and pops
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void mod(stack_t **head, unsigned int line_number)
{
	int node_count = 0, result;
	stack_t *temp = *head, *current = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_arguments_node();
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		node_count++;
		temp = temp->next;
	}
	if (node_count < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_arguments_node();
		exit(EXIT_FAILURE);
	}
	else
	{
		if (current != NULL && current->next != NULL)
		{
			if (current->n == 0)
			{
				fprintf(stderr, "L%u: division by zero\n", line_number);
				free_arguments_node();
				exit(EXIT_FAILURE);
			}
			result = current->next->n % current->n;
			current->next->n = result;
			*head = current->next;
			current->next->prev = NULL;
			free(current);
		}
	}
}

/**
 * pchar - Prints the ASCII value of the data on top of the stack
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_arguments_node();
		exit(EXIT_FAILURE);
	}
	if (!(current->n > 127 || current->n < 0))
	{
		_putchar(current->n);
		_putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_arguments_node();
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - Prints the ASCII value of all data in the stack
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	if (*head == NULL)
	{
		_putchar('\n');
		return;
	}
	while (current != NULL)
	{
		if (current->n == 0)
			break;
		if (current->n >= 32 && current->n <= 126)
		{
			_putchar(current->n);
		}
		else
			break;
		current = current->next;
	}
	_putchar('\n');
}

/**
 * rotl - Rotates the stack to the bottom
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int a;
	(void)line_number;

	if (current == NULL)
		return;
	a = current->n;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->n = a;
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
