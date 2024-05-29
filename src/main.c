#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "built_in_commands.h"
#include "input_functions.h"

/**
 * @brief Continuously runs the shell program.
 *
 * This function continuosly loops, asking the user for input
 * until they want to exit the program. Checks input and executes
 * programs as specified by the user.
 *
 * @see ls() echo()
 */
void loop() {
    while (true) {
        struct user_input *input = prompt_and_return("> ");

        if (input->tokens == NULL) {
            continue;
        } else if (strcmp(input->tokens[0], "ls") == 0) {
            ls();
        } else if (strcmp(input->tokens[0], "cd") == 0) {
            printf("TODO: IMPLEMENT cd\n");
        } else if (strcmp(input->tokens[0], "mkdir") == 0) {
            printf("TODO: IMPLEMENT mkdir\n");
        } else if (strcmp(input->tokens[0], "touch") == 0) {
            printf("TODO: IMPLEMENT touch\n");
        } else if (strcmp(input->tokens[0], "exit") == 0) {
            return;
        } else {
            printf("csh: command not found: %s\n", input->tokens[0]);
        }
    }
}

/**
 * @brief Main function that starts the shell.
 *
 * Main function that starts the shell.
 *
 * @return An integer indicating the shell ran successfully. 
 */
int main(void) {
    
    loop();

    return 0;
}
