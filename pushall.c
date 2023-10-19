#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define STACK_SIZE 100

int stack[STACK_SIZE];  // The stack to store integers
int stack_pointer = 0;  // Points to the top of the stack

void push(int value) {
    if (stack_pointer < STACK_SIZE) {
        stack[stack_pointer] = value;
        stack_pointer++;
    } else {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

void pall() {
    int i;
    for (i = stack_pointer - 1; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    // Read and interpret Monty bytecode from a file
    FILE *file = fopen("bytecodes/00.m", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the bytecode file\n");
        return EXIT_FAILURE;
    }

    char opcode[50];
    int arg;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &arg) != 1) {
                fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(arg);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "Error: L%d: Unknown opcode: %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}