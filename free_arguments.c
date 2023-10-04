#include "monty.h"

/**
 * free_arguments_node - free memory
 * Return: Nothing
 */
void free_arguments_node(void)
{
	free(arguments);
}

/**
 * free_toks_arr - free memory
 * Return: Nothing
 */
void free_toks_arr(void)
{
	int j = 0;

	if (arguments->toks_arr == NULL)
	{
		return;
	}
	while (arguments->toks_arr[j])
	{
		free(arguments->toks_arr[j]);
		j++;
	}
	free(arguments->toks_arr);
	arguments->toks_arr = NULL;
}

/**
 * freeMemory_closeFile - function that free all
 * allocated memory and close file if <int> is not an
 * integer or if there is no argument given to push
 * Return: Nothing
 */
void freeMemory_closeFile(void)
{
	if (arguments->file != NULL)
	{
		if (fclose(arguments->file) == EOF)
		{
			fprintf(stderr, "Error closing the file.\n");
		}
	}
	if (arguments->head != NULL)
	{
		free_arguments_node();
	}
	if (arguments->instruct != NULL)
	{
		free(arguments->instruct);
	}
	if (arguments->toks_arr != NULL)
	{
		free_toks_arr();
	}
	free(arguments);
}

/**
 * free_lists - free all nodes in the list
 * Return: Nothing
 */
void free_lists(void)
{
	stack_t *current, *temp;

	if (arguments->head == NULL)
	{
		return;
	}
	current = arguments->head;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
