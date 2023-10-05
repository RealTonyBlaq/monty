# **C - Stacks, Queues - LIFO, FIFO**
A stack in C is nothing but a linear data structure that follows the LIFO rule (Last In First Out). In a stack, both insertion (push) and deletion (pop) take place from just one end, that is, from the top.

In contrast to a stack, a queue in C is nothing but a linear data structure that follows the FIFO rule (First In First Out). Insertion is done from the back (the rear end) and deletion is done from the front.
## Monty
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## MONTY BYTE CODE FILES

Files containing Monty byte codes usually have the _.m_ extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

**The monty program**

Usage: `monty file`

- where file is the path to the file containing Monty byte codes.

## OPCODES AND FUNCTIONS
- `Push`: The opcode pushes an element to the stack.
- `pall`: The opcode prints all the values on the stack, starting from the top of the stack.
- `pint`: Prints the element at the top of the stack.
- `pop`: Removes the top element of the stack.
- `nop`: The opcode doesn’t do anything.
- `swap`: The opcode swaps the top two elements of the stack.
- `add`: The opcode adds the top two elements of the stack.
    - The top element of the stack contains the result
    - The stack is one element shorter
- `sub`: The opcode subtracts the top element of the stack from the second top element of the stack.
    - The top element of the stack contains the result
    - The stack is one element shorter
- `div`: The opcode divides the second top element of the stack by the top element of the stack.
    - The top element of the stack contains the result
    - The stack is one element shorter
- `mod`: The opcode computes the rest of the division of the second top element of the stack by the top element of the stack.
    - The top element of the stack contains the result
    - The stack is one element shorter
- `mul`: The opcode mul multiplies the second top element of the stack with the top element of the stack.

    - The top element of the stack contains the result
    - The stack is one element shorter
- `pchar`: The opcode prints the char at the top of the stack, followed by a new line.
    - The integer stored at the top of the stack is treated as the ascii value of the character to be printed
- `pstr`: The opcode prints the string starting at the top of the stack, followed by a new line.
    - The integer stored at the top of the stack is treated as the ascii value of the character to be printed.
- `rotl`: The opcode rotates the stack to the top.
    - The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
- `rotr`: The opcode rotates the stack to the bottom.
    - The last element of the stack becomes the top element of the stack
- `stack` and `queue`: 

        "Stack" sets the format of the data to a stack (LIFO). This is the default behavior of the program.
        "Queue" sets the format of the data to a queue (FIFO).

        When switching mode:

        The top of the stack becomes the front of the queue
        The front of the queue becomes the top of the stack.

## BRAIN F*CK
Brainfuck is an esoteric programming language created in 1993 by Urban Müller.
Notable for its extreme minimalism, the language consists of only eight simple commands, a data pointer and an instruction pointer.
