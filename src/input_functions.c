#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_functions.h"

#define MAX_BUFFER 256

/**
 * @brief Returns a pointer to a substring of string without leading\
 *      and trailing whitespace. 
 *
 * This function takes a string as input, and returns a substring of 
 * the input string without any leading or trailing whitespace. This
 * function does not modify the original string. Instead, it allocates
 * memory, using malloc(), for the trimmed substring and returns a 
 * pointer to the start of the substring.
 *
 * @param[in] string String the user wishes to have trimmed down.
 *
 * @return Pointer to a substring of string without any leading or\
 *      trailing whitespace.
 */
char *trim_whitespace(char *string) {
    int len = strlen(string);
    int start = 0;
    int end = len - 1;
    char *substring = NULL;
    int substring_len = -1;

    // Calculate start index of trimmed substring.
    for (int i = 0; i < len && string[i] == ' '; i++) {
        start++;
    }

    // All whitespace or empty string edge case.
    if (start - 1 == end) {
        substring = malloc(sizeof(char));
        substring[0] = '\0';
        return substring;
    }

    // Calculate end index of trimmed substring.
    for (int i = len - 1; i >= 0 && string[i] == ' '; i--) {
        end--;
    }

    // +1 To get actual length from indices.
    substring_len = (end - start) + 1; 

    // Construct and allocate substring.
    substring = malloc((substring_len + 1) * sizeof(char)); // +1 for null terminating char.
    strncpy(substring, (string + start), substring_len);
    substring[substring_len] = '\0';

    return substring;
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
 * @brief Takes a formatted input line and turns it into a user_input
 *      struct. 
 * 
 * This function handles taking a user input string and breaking it up into 
 * the components that go into a user_input struct. This allows parsing of input
 * for arguments to be a lot easier.
 * 
 * @param[in] input_line A string without any leading or trailing whitespace, or 
 *      without any newline characters. 
 * 
 * @return A user_input struct. See input_functions.h for more information on 
 *      how a user_input struct is formatted. 
*/
struct user_input *interpret_input(char *input_line) {
    // Handle edge cases.
    // Empty string
    bool empty = strcmp(input_line, "") == 0;
    if (empty) {
		struct user_input *input_struct = malloc(sizeof(struct user_input *));

        input_struct->tokens = NULL;
        input_struct->num_tokens = 0;
        input_struct->original_string = strdup(input_line);

		return input_struct;
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
		struct user_input *input_struct = malloc(sizeof(struct user_input *));

        input_struct->tokens = NULL;
        input_struct->num_tokens = 0;
        input_struct->original_string = strdup(input_line);

		return input_struct;
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
	
	// Init variables. 
	int *num_tokens = malloc(sizeof(int));
	*num_tokens = 0; 
	char *delim = malloc(sizeof(char));
	*delim = ' ';
	char **tokens = split_line(input_line, delim, num_tokens);

	// Create input struct. 
	struct user_input *input_struct = malloc(sizeof(struct user_input *));

	input_struct->tokens = malloc((*num_tokens + 1) * sizeof(char *));	// +1 for NULL delim.
	for (int i = 0; i < *num_tokens; i++) {
		input_struct->tokens[i] = strdup(tokens[i]);
	}
	input_struct->tokens[*num_tokens] = NULL; 
	input_struct->num_tokens = *num_tokens;
	input_struct->original_string = strdup(input_line);

	// Free memory used by split_line().
	free_tokens(tokens);

	return input_struct;
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
		tokens[i] = NULL;	// Marks that input[i] is free.
    }
    free(tokens);
	tokens = NULL;	// Marks that input is free. 
}

/**
 * @brief Gets and returns input from the user.
 *
 * This function gets input from user and uses malloc() to store
 * the string in memory. User of this function must use free()
 * to free the returned value. 
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
struct user_input *prompt(char *prompt_string_to_display) {
    char *input_line = malloc(sizeof(char *));
    struct user_input *input = NULL;

    printf("%s", prompt_string_to_display);

    input_line = get_input_line();
    input = interpret_input(input_line);
    
    return input;
}
