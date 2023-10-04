#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <ctype.h>

void check_num_of_argument(int argc);
void initialize_arguments_node(void);
void fetch_file_content(char *user_file);
void memory_allocation_failed(void);
void fetch_failed(char *user_file);
void free_arguments_node(void);
void tokenize_read_line(void);
void free_toks_arr(void);
void fetch_instruction(void);
void close_file(void);
void execute_instruction(void);
void instruction_not_valid(void);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arguments - argument node
 * @file: file stream
 * @toks_arr: tokens array
 * @read: buffer for fgets
 * @file_line_num: current file line number
 * @toks_num: num of tokend per line
 * @instruct: instructions
 * @head: pointer to top node of stack
 * @top: ponter to top node
 * @stack_queue_switch: switches the list from LIFO to FIFO and vice versa
 *
 */
typedef struct arguments
{
	FILE *file;
	char **toks_arr;
	char read[100];
	unsigned int file_line_num;
	int toks_num;
	instruction_t *instruct;
	stack_t *head;
	int stack_queue_switch;
	int top;
} args;

extern args *arguments;

void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void divide(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void stack(stack_t **head, unsigned int line_number);
void queue(stack_t **head, unsigned int line_number);
int _putchar(char c);
void mul(stack_t **head, unsigned int line_number);
int check_string(char *string);
void free_lists(void);
void freeMemory_closeFile(void);
void handle_queue(stack_t *current, stack_t *new_node);

#endif /* MONTY_H */
