#ifndef BUILT_IN_COMMANDS_H
#define BUILT_IN_COMMANDS_H

#include "input_functions.h"

/**
 * @brief Lists all files in working directory.
 *
 * Lists all files in the working directory. Equivalent to the 
 * command by the same name in bash.
 */
void ls();

/**
 * @brief Changes the current working directory.
 *
 * Given an array of strings, changes the current working
 * directory to the string in the 1st index. 
 *
 * @param[in] Array of strings representing command
 * 		line args.
 *
 * @return An integer denoting whether the function worked.
 * 		0 if it worked; 1 if the number of args is incorrect;
 * 		2 if the directory specified doesn't exist. 
 */
int cd(char **args);

/**
 * @brief Prints the current working directory.
 *
 * Prints the current working directory using getcwd().
 */
void pwd();

/**
 * @brief Given a directory name, makes a directory with the given name.
 *
 * Given a string dir_name representing the new directory name,
 * attempts to create a directory with that name. The new directory
 * is created and read, write, and execute permissions are given to 
 * everyone by default. If the directory creation failes, the function
 * will print an error to the stdout.
 */
void mkdir_custom(char *dir_name);

/**
 * @brief Creates a file named file_name. 
 *
 * This function takes the string passed to it and creates a new
 * file with that name. 
 */
void touch(char *file_name);

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
