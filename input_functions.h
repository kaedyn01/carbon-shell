#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

/* This function prints the character indicating a user
 * should begin typing their command. 
 */
void prompt();

/* This function gets input from user and uses malloc()
 * to store in input in an array of characters. 
 */
char *get_input_line();

#endif