#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_functions.h"

#define MAX_BUFFER 256

// TODO: Fix memory leaks caused by this function.
char *trim_whitespace(char *string) {
    int len = strlen(string);
    int start = 0;
    int end = len - 1;
    char *substring = NULL;
    int substring_len = -1;

    
    // Calculate start index of trimmed substring.
    for (int i = 0; i < len && string[i] == ' '; i++) {
        printf("i: %d\n", i);
        printf("i char: \'%c\'\n", string[i]);
        printf("start: %d\n", start);
        start++;
    }

    // All whitespace or empty string case.
    if (start - 1 == end) {
        substring = malloc(sizeof(char));
        substring[0] = '\0';

        // TDWD
        printf("%d\n", start);
        printf("\'%c\'\n", string[start]);
        printf("%d\n", end);
        printf("\'%c\'\n", string[end]);
        printf("%d\n", len);
        printf("%d\n", substring_len);
        printf("\"%s\"\n", substring);
        
        return substring;
    }

    // Calculate end index of trimmed substring.
    for (int i = len - 1; i >= 0 && string[i] == ' '; i--) {
        printf("i: %d\n", i);
        printf("i char: \'%c\'\n", string[i]);
        printf("end: %d\n", end);
        end--;
    }

    // +1 To account get actual length from indices.
    substring_len = (end - start) + 1; 

    // Construct and allocate substring.
    substring = malloc((substring_len + 1) * sizeof(char)); // +1 for null terminating char.
    strncpy(substring, (string + start), substring_len);
    substring[substring_len] = '\0';

    // TDWD
    printf("%d\n", start);
    printf("\'%c\'\n", string[start]);
    printf("%d\n", end);
    printf("\'%c\'\n", string[end]);
    printf("%d\n", len);
    printf("%d\n", substring_len);
    printf("\"%s\"\n", substring);

    return substring;
}

struct user_input *interpret_input(char *input_line) {
    // Handle edge cases.
    // Empty string
    bool empty = strcmp(input_line, "") == 0;
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
 * @brief Frees all the memory allocated by interpret_input().
 *
 * This function takes an array of strings terminated by a null
 * pointer and frees all of its memory.
 *
 * @param[in] tokens The array of strings, terminated by a null\ 
 *      pointer, that the user wants to free from memory.
 *
 * @see interpret_input()
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
    char *trimmed_line = NULL;

    if (line == NULL) {
        printf("ERROR: Memory allocation failed.\n");
        abort();
    }

    fgets(line, MAX_BUFFER, stdin);
    line[strcspn(line, "\n")] = '\0';   // Removes added newline from user input.
    
    trimmed_line = trim_whitespace(line);

    free(line);

    return trimmed_line;
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
    struct user_input *input = NULL;

    printf("%s", prompt_string);

    input_line = get_input_line();
    input = interpret_input(input_line);
    
    return input;
}
