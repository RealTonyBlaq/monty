#include "monty.h"

/**
 * fetch_failed - function that print error message
 * when file cannot be open
 * @user_file: file input at run of program
 * Return: Nothing
 */
void fetch_failed(char *user_file)
{
	fprintf(stderr, "Error: Can't open file %s\n", user_file);
	free_arguments_node();
	exit(EXIT_FAILURE);
}

/**
 * memory_allocation_failed - malloc failed
 * Return: Nothing
 */
void memory_allocation_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arguments_node();
	exit(EXIT_FAILURE);
}
