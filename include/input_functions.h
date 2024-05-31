#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

/**
 * A struct that holds an array of tokens that, when put together
 * using spaces, form user input. It also holds the number of tokens
 * in the array, along with the original string that typed by 
 * the user of the shell.
 */
struct user_input {
    char **tokens;
    int num_tokens;
    char *original_string;
};

// Max length that an input string can be.
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
char *trim_whitespace(char *string);

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
char **split_line(char *line, char *delim, int *num_tokens);

void free_user_input(struct user_input *input);

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
struct user_input *interpret_input(char *input_line);
 
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
struct user_input *prompt_and_return(char *prompt_string);

#endif
