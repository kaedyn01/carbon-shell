#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "input_functions.h"

#define MAX_BUFFER 256

struct user_input *interpret_input(char *input_line, char *delim) {
    // Handle edge cases.
    // Empty string
    bool empty = strcmp(input_line, " ") == 0;
    if (empty) {
        return NULL;
    }

    // All whitespace. 
    bool all_whitespace = true;
    char *temp_line = strdup(input_line);

    for (int i = 0; temp_line[i] != '\0'; i++) {
        if (temp_line[i] != ' ') {
            all_whitespace = false;
            break;
        }
    }

    free(temp_line);

    if (all_whitespace) {
        return NULL;
    }

    // No delimiters in string.
    bool no_delimiters = true;
    temp_line = strdup(input_line);

    for (int i = 0; temp_line[i] != '\0'; i++) {
        if (temp_line[i] == ' ') {
            no_delimiters = false;
            break;
        }
    }

    free(temp_line);

    if (no_delimiters) {
        struct user_input *input_struct = malloc(sizeof(struct user_input *));

        input_struct->tokens = malloc(2 * sizeof(char *));
        input_struct->tokens[0] = strdup(input_line);
        input_struct->tokens[1] = NULL;
        input_struct->num_tokens = 1;
        input_struct->original_string = strdup(input_line);

        return input_struct;
    }

    // TODO: Implement rest.

    // Init variables.
        // args count
        // string array 
        // temp string 

    // Split input line.

    // Free mem.

    // Return.

    return NULL;
}

/**
 * @brief Splits string by passed delimeter.
 *
 * This function takes a string and delimeter as input, and
 * splits the string into an array of substrings terminated
 * by a null pointer. This function also stores the length
 * of the array in the integer pointer num_tokens.
 *
 * @param[in] line The line that the user wants to split.
 *
 * @param[in] delim The delimiter that the string will by split\
 *      by.
 *
 * @return An array of strings terminated by a null pointer.
 */
char **split_line(char *line, char *delim, int *num_tokens) {
    // Handle no command case.
    if (strcmp(line, "") == 0) {
        return NULL;
    }

    char *line_copy = NULL;
    int count = 0;
    char *token = NULL;
    char **tokens = NULL;

    // Handle case where line is too short to be split.
    if (strlen(line) < strlen(delim) + 2) {
        tokens = malloc(2 * sizeof(char *));
        tokens[0] = strdup(line);
        tokens[1] = NULL;
        *num_tokens = 1;
        return tokens;
    }

    // Count number of tokens.
    line_copy = strdup(line);
    token = strtok(line_copy, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }
    free(line_copy);

    // Allocate memory for the array of lines.
    tokens = malloc((count + 1) * sizeof(char *));
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

/**
 * @brief Frees all the memory allocated by prompt().
 *
 * This function takes an array of strings terminated by a null
 * pointer and frees all of its memory.
 *
 * @param[in] tokens The array of strings, terminated by a null\ 
 *      pointer, that the user wants to free from memory.
 *
 * @see prompt()
 */
void free_tokens(char **tokens) {
    for(int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

/**
 * @brief Gets and returns input from the user.
 *
 * This function gets input from user and uses malloc() to store
 *
 * @return A string holding user input.
 */
char *get_input_line() {
    char *line = malloc(sizeof(char) * MAX_BUFFER);

    if (line == NULL) {
        printf("ERROR: Memory allocation failed.\n");
        abort();
    }

    fgets(line, MAX_BUFFER, stdin);
    line[strcspn(line, "\n")] = '\0';   // Removes added newline from user input.
    return line;
}

/**
 * @brief Prompts for input and returns input as array of strings.
 * 
 * This function prints the character indicating a user
 * should begin typing their command. Then gets the user's
 * input and returns it as an array of strings. It also 
 * takes an int pointer as an arg to store the number 
 * of arguements in the user's input.
 *
 * @param[in] prompt_string The string displayed to the user when\
 *      prompting for input.
 *
 * @param[out] num_args The variable used to save the number of elements\
 *      in the array of strings.
 *
 * @param[out] original_input The variable used to save the original string\
 *      input.
 *
 * @return An array of strings, terminated by a NULL pointer, where each\ 
 *      string is word in the command that the user typed.
 *
 * @see free_tokens() 
 */
struct user_input *prompt(char *prompt_string) {
    char *input_line = malloc(sizeof(char *));
    char *delim = malloc(sizeof(char *));
    *delim = ' ';
    struct user_input *input = NULL;

    printf("%s", prompt_string);

    input_line = get_input_line();
    input = interpret_input(input_line, delim);

    free(input_line);
    free(delim);
    
    return input;
}
