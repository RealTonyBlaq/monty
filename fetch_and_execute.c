#include "monty.h"

/**
 * fetch_instruction - get instruction
 * Return: Nothing
 */
void fetch_instruction(void)
{
	int i;
	instruction_t instructions[] = {
		{"push", &push}, {"pall", &pall}, {"pint", &pint},
		{"pop", &pop}, {"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"sub", &sub}, {"div", &divide},
		{"mul", &mul}, {"mod", &mod}, {"pchar", &pchar},
		{"pstr", &pstr}, {"rotl", &rotl}, {"stack", &stack},
		{"queue", &queue}, {"rotr", &rotr}, {NULL, NULL}
	};

	if (arguments->toks_num == 0)
	{
		return;
	}
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, arguments->toks_arr[0]) == 0)
		{
			arguments->instruct->opcode = instructions[i].opcode;
			arguments->instruct->f = instructions[i].f;
			return;
		}
	}
	instruction_not_valid();
}

/**
 * instruction_not_valid - print invalid instruction
 * Return: Nothing
 */
void instruction_not_valid(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			arguments->file_line_num, arguments->toks_arr[0]);

	close_file();
	free_toks_arr();
	free_arguments_node();
	free(arguments->instruct);
	exit(EXIT_FAILURE);
}

/**
 * execute_instruction - execute instructions
 * Return: Nothing
 */
void execute_instruction(void)
{

	if (arguments->toks_arr == 0)
	{
		return;
	}
	arguments->instruct->f(&arguments->head, arguments->file_line_num);
}
