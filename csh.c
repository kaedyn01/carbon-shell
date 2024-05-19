#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "built_in_commands.h"

#define TRUE 1 
#define FALSE 0
#define MAX_BUFFER 256

/* This function prints the character indicating a user
 * should begin typing their command. 
 */
void prompt() {
    printf("> ");
}

/* This function gets input from user and uses malloc()
 * to store in input in an array of characters. 
 */
char *get_input_line() {
    char *line = malloc(sizeof(char) * MAX_BUFFER);
    fgets(line, MAX_BUFFER, stdin);               
    line[strcspn(line, "\n")] = '\0';   // Removes added newline from user input.
    return line;
}

/* This function is the main loop for the shell. It gets
 * user input and executes the specified command.
 */
void loop() {
    while (TRUE) {
        prompt();
        char *line = get_input_line();

        if (strcmp(line, "ls") == 0) {
            ls();
        } else if (strcmp(line, "cd") == 0) {
            printf("TODO: IMPLEMENT cd\n");
        } else if (strcmp(line, "mkdir") == 0) {
            printf("TODO: IMPLEMENT mkdir\n");
        } else if (strcmp(line, "touch") == 0) {
            printf("TODO: IMPLEMENT touch\n");
        } else if (strcmp(line, "exit") == 0) {
            free(line);
            return;
        } else {
            echo(line);
        }

        free(line);
    }
}

/* Main function that starts the shell.
 */
int main(void) {
    
    loop();

    return 0;
}
