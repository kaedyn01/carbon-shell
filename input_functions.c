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

/* This function takes in a string as input, splits it by the 
 * inputted delimiter char, and returns the split string as 
 * as an array of strings. Also stores the number of strings
 * in num_tokens int pointer. 
 *
 * The corresponding free function "free_tokens" frees all the 
 * memory allocated by this function.
 */
char **split_line(char *line, char *delim, int *num_tokens) {
    char *line_copy = strdup(line);
    int count = 0;
    char *token;

    // Count number of tokens.
    token = strtok(line_copy, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }
    free(line_copy);

    // Allocate memory for the array of lines.
    char **tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Split the line and store the tokens.
    line_copy = strdup(line); // Make another copy of the input line.
    count = 0;
    token = strtok(line_copy, delim);
    while (token != NULL) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, delim);
    }
    tokens[count] = NULL;
    free(line_copy);

    *num_tokens = count;
    return tokens;
}

/* Frees all the memory of an array of strings allocated by 
 * split_line.
 */
void free_tokens(char **tokens) {
    for(int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
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
