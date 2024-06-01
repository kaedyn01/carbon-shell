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
        char **args = get_args();

        if (args[0] == NULL) {
            free_args(args);
            continue;
        } else if (strcmp(args[0], "ls") == 0) {
            ls();
        } else if (strcmp(args[0], "cd") == 0) {
            /**
            int result = cd(input);
            if (result == 1) {
                printf("Did not specify which directory to change to.\n");
                printf("Use: cd /exmaple/directory\n");
            } else if (result == 2) {
                printf("The directory entered doesn't exist, please try again.\n");
            }
            */
        } else if (strcmp(args[0], "mkdir") == 0) {
            printf("TODO: IMPLEMENT mkdir\n");
        } else if (strcmp(args[0], "touch") == 0) {
            printf("TODO: IMPLEMENT touch\n");
        } else if (strcmp(args[0], "exit") == 0) {
            return;
        } else {
            printf("csh: command not found: %s\n", args[0]);
        }

        free_args(args);
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

    char **args = get_args();

    for (int i = 0; args[i] != NULL; i++) {
        printf("\"%s\"\n", args[i]);
    }
    if (args == NULL) {
        printf("args is NULL.\n");
    }
    if (args[0] == NULL) {
        printf("First elem is NULL.\n");
    }

    printf("{ ");
    for (int i = 0; args[i] != NULL; i++) {
        for (int j = 0; args[i][j] != '\0'; j++) {
            printf("\'%c\', ", args[i][j]);
        }
        printf("\n");
    }
    printf(" }\n");

    // loop();

    return 0;
}
