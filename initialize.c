#include "monty.h"

/**
 * check_num_of_argument - function check if the user does not give
 * any file or more than one argument to your program
 * @argc: argument count
 * Return: nothing
 */
void check_num_of_argument(int argc)
{
	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * initialize_arguments_node - function that initialize
 * the arguments node members to NULL
 * Return: Nothing
 */
void initialize_arguments_node(void)
{
	arguments = malloc(sizeof(args));
	if (arguments == NULL)
	{
		memory_allocation_failed();
	}
	arguments->file = NULL;
	arguments->toks_num = 0;
	arguments->file_line_num = 0;
	arguments->head = NULL;
	arguments->top = -1;
	arguments->stack_queue_switch = 1;
}

/**
 * fetch_file_content - function that fetch the content of
 * the user inputted file,
 * @user_file: file the user run the program with
 * Return: Nothing
 */
void fetch_file_content(char *user_file)
{
	arguments->file = fopen(user_file, "r");
	if (arguments->file == NULL)
	{
		fetch_failed(user_file);
	}
}

/**
 * close_file - closes an open file
 * Return: Nothing
 */
void close_file(void)
{
	if (arguments->file == NULL)
	{
		return;
	}
	fclose(arguments->file);
	arguments->file = NULL;
}
