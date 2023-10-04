#include "monty.h"

/**
 * pop - Deletes the node at the top of the stack
 * @head: The whole stack
 * @line_number: Current line number
 * Return: Nothing
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL || arguments->top < 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeMemory_closeFile();
		exit(EXIT_FAILURE);
	}

	current = *head;

	if (current->next == NULL)
	{
		*head = NULL;
	}

	if (current->next != NULL)
	{
		*head = current->next;
		current->next->prev = NULL;
	}
	free(current);
}

/**
 * swap - Swaps the first two data on the stack
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int line_number)
{
	int a;
	stack_t *current;

	current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(arguments->instruct);
		free_toks_arr();
		free_lists();
		close_file();
		free_arguments_node();
		/**freeMemory_closeFile();**/

		exit(EXIT_FAILURE);
	}
	else
	{
		a = current->n;
		current->n = current->next->n;
		current->next->n = a;
	}
}

/**
 * add - adds the first two data on the stack and pops
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void add(stack_t **head, unsigned int line_number)
{
	int node_count = 0, sum;
	stack_t *temp = *head, *current = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
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
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_arguments_node();
		exit(EXIT_FAILURE);
	}
	else
	{
		if (current != NULL && current->next != NULL)
		{
			sum = current->n + current->next->n;
			current->next->n = sum;
			*head = current->next;
			current->next->prev = NULL;
			free(current);
		}
	}
}

/**
 * sub - Subtracts the first two data on the stack and pops
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void sub(stack_t **head, unsigned int line_number)
{
	int node_count = 0, diff;
	stack_t *temp = *head, *current = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_arguments_node();
		exit(EXIT_FAILURE);
	}
	else
	{
		if (current != NULL && current->next != NULL)
		{
			diff = current->next->n - current->n;
			current->next->n = diff;
			*head = current->next;
			current->next->prev = NULL;
			free(current);
		}
	}
}

/**
 * divide - Divides the first two data on the stack and pops
 * @head: The whole stack
 * @line_number: The current line
 * Return: Nothing
 */
void divide(stack_t **head, unsigned int line_number)
{
	int node_count = 0, result;
	stack_t *temp = *head, *current = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
			result = current->next->n / current->n;
			current->next->n = result;
			*head = current->next;
			current->next->prev = NULL;
			free(current);
		}
	}
}
