#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

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
char **split_line(char *string, char *delim, int *num_tokens);

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
void free_tokens(char **tokens);

/**
 * @brief Gets and returns input from the user.
 *
 * This function gets input from user and uses malloc() to store
 * the input in a string and returns said string to the user.
 *
 * @return A string holding user input.
 */
char *get_input_line();

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
char **prompt(char *prompt_string, int *num_args, char *original_input);

#endif