#ifndef BUILT_IN_COMMANDS_H
#define BUILT_IN_COMMANDS_H

/**
 * @brief Lists all files in working directory.
 *
 * Lists all files in the working directory. Equivalent to the 
 * command by the same name in bash.
 */
void ls();

void cd_logic(char *destination_dir);

void cd(struct user_input *input);

/**
 * @brief Prints inputted string to the stdout.
 *
 * Takes a string as input, and outputs said string to the
 * stdout.
 *
 * @param[in] string String to be outputted.
 */
void echo(char *string);

#endif