#include "monty.h"

/**
 * push - insert integer value at the beginning of a stack
 * @head: newly created stack
 * @line_number: line number in the file
 * Return: Nothing
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *current, *new_node;

	if (arguments->toks_num <= 1 || !(check_string(arguments->toks_arr[1])))
	{
		freeMemory_closeFile();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		memory_allocation_failed();
	else
	{
		if (*head == NULL)
		{
			*head = new_node;
			new_node->prev = NULL;
			new_node->next = NULL;
			new_node->n = (int)atoi(arguments->toks_arr[1]);
		}
		else
		{
			if (arguments->stack_queue_switch == 1)
			{
				current = *head;
				*head = new_node;
				new_node->prev = NULL;
				new_node->next = current;
				current->prev = new_node;
				new_node->n = (int)atoi(arguments->toks_arr[1]);
			}
			else
			{
				current = *head;
				handle_queue(current, new_node);
			}
		}
	}
	arguments->top += 1;
}

/**
 * handle_queue - function that handle the queue.
 * @current: current
 * @new_node: newly created node
 * Return: Nothing
 */
void handle_queue(stack_t *current, stack_t *new_node)
{
	while (current->next != NULL)
		current = current->next;
	new_node->prev = current;
	current->next = new_node;
	new_node->next = NULL;
	new_node->n = (int)atoi(arguments->toks_arr[1]);
}

/**
 * check_string - check if string is a valid integer
 * @string: string to check
 * Return: an integer value
 */
int check_string(char *string)
{
	int i = 0;

	while (string[i])
	{
		if (i == 0 && string[i] == '-' && string[i + 1])
		{
			i++;
			continue;
		}
		if (string[i] < '0' || string[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * pall - function to print the data in stack
 * @head: new created stack
 * @line_number: line number in file
 * Return: Nothing
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (arguments->top == -1)
		return;

	current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @head: pointer to the first node in stack
 * @line_number: The current line number
 * Return: Nothing
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (arguments->top == -1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		freeMemory_closeFile();
		exit(EXIT_FAILURE);
	}
	current = *head;
	printf("%d\n", current->n);
}
