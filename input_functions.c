#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_functions.h"

#define MAX_BUFFER 256

/* This function prints the character indicating a user
 * should begin typing their command. 
 */
void prompt() {
    printf("> ");
}

/* This function gets input from user and uses malloc()
 * to store in input in an array of characters. 
 */
char *get_input_line() {
    char *line = malloc(sizeof(char) * MAX_BUFFER);
    fgets(line, MAX_BUFFER, stdin);               
    line[strcspn(line, "\n")] = '\0';   // Removes added newline from user input.
    return line;
}
