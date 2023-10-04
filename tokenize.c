#include "monty.h"

/**
 * tokenize_read_line - function that tokenize each line in file
 * Return: Nothing
 */
void tokenize_read_line(void)
{
	char *read_copy = NULL, *token = NULL, *delimiter = " \n";
	int i = 0;

	read_copy = malloc(sizeof(char) * (strlen(arguments->read) + 1));
	strcpy(read_copy, arguments->read);
	arguments->toks_num = 0;
	token = strtok(read_copy, delimiter);
	if (token && token[0] == '#')
	{
		free(read_copy);
		return;
	}
	while (token)
	{
		arguments->toks_num += 1;
		token = strtok(NULL, delimiter);
	}
	arguments->toks_arr = malloc(sizeof(char *) * (arguments->toks_num + 1));
	strcpy(read_copy, arguments->read);
	token = strtok(read_copy, delimiter);
	while (token)
	{
		arguments->toks_arr[i] = malloc(strlen(token) + 1);
		if (arguments->toks_arr[i] == NULL)
		{
			memory_allocation_failed();
		}
		strcpy(arguments->toks_arr[i], token);
		token = strtok(NULL, delimiter);
		i++;
	}
	arguments->toks_arr[i] = NULL;

	free(read_copy);
}
