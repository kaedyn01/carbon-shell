#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

/* This function prints the character indicating a user
 * should begin typing their command. 
 */
void prompt();

/* This function takes in a string as input, splits it by the 
 * inputted delimiter char, and returns the split string as 
 * as an array of strings. Also stores the number of strings
 * in num_tokens int pointer. 
 *
 * The corresponding free function "free_tokens" frees all the 
 * memory allocated by this function.
 */
char **split_line(char *string, char *delim, int *num_tokens);

/* Frees all the memory of an array of strings allocated by 
 * split_line. 
 */
void free_tokens(char **tokens);

/* This function gets input from user and uses malloc()
 * to store in input in an array of characters. 
 */
char *get_input_line();

#endif