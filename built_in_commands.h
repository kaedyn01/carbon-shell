#ifndef BUILT_IN_COMMANDS_H
#define BUILT_IN_COMMANDS_H

/* This function serves to add the functionality 
 * of listing all the contents of the current directory.
 * Equivalent to "ls" in bash.
 */
void ls();

/* Given a string. This function will output said string
 * to the standard out (most likely the terminal window).
 */
void echo(char *string);

#endif