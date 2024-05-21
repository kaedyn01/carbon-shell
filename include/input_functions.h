#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

struct user_input {
    char **tokens;
    int num_tokens;
    char *original_string;
};

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
struct user_input *prompt(char *prompt_string);

#endif