#include "monty.h"

args *arguments = NULL;

/**
 * main - Entry point
 * @av: argument vector
 * @argc: argument count
 * Return: 0 successful
 */

int main(int argc, char **av)
{
	check_num_of_argument(argc);
	initialize_arguments_node();
	fetch_file_content(av[1]);

	while ((fgets(arguments->read, sizeof(arguments->read),
					arguments->file)) != NULL)
	{
		arguments->file_line_num += 1;
		tokenize_read_line();
		arguments->instruct = malloc(sizeof(instruction_t));
		if (arguments->instruct == NULL)
		{
			memory_allocation_failed();
		}
		arguments->instruct->opcode = NULL;
		arguments->instruct->f = NULL;

		fetch_instruction();
		execute_instruction();
		free_toks_arr();
		free(arguments->instruct);
	}
	free_lists();
	close_file();
	free_arguments_node();
	return (0);
}
