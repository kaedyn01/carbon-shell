#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "built_in_commands.h"
#include "input_functions.h"

#define TRUE 1 
#define FALSE 0

/* This function is the main loop for the shell. It gets
 * user input and executes the specified command.
 */
void loop() {
    while (TRUE) {
        int *num_args = malloc(sizeof(int));
        char **user_args = prompt("> ", num_args);

        if (strcmp(user_args[0], "ls") == 0) {
            ls();
        } else if (strcmp(user_args[0], "cd") == 0) {
            printf("TODO: IMPLEMENT cd\n");
        } else if (strcmp(user_args[0], "mkdir") == 0) {
            printf("TODO: IMPLEMENT mkdir\n");
        } else if (strcmp(user_args[0], "touch") == 0) {
            printf("TODO: IMPLEMENT touch\n");
        } else if (strcmp(user_args[0], "exit") == 0) {
            free(num_args);
            free_tokens(user_args);
            return;
        } else {
            int i = 0;
            while (user_args[i] != NULL) {
                printf("\"%s\"\n", user_args[i]);
                i++;
            }
        }

        free(num_args);
        free_tokens(user_args);
    }
}

/* Main function that starts the shell.
 */
int main(void) {
    
    loop();

    return 0;
}
