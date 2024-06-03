#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
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
		printf("-> ");

        char **args = get_args();

        if (args[0] == NULL) {

            free_args(args);
            continue;

        } else if (strcmp(args[0], "ls") == 0) {

            ls();

        } else if (strcmp(args[0], "cd") == 0) {

            int result = cd(args);
            if (result == 1) {
                printf("Did not specify which directory to change to.\n");
                printf("Use: cd /exmaple/directory\n");
            } else if (result == 2) {
                printf("The directory entered doesn't exist, please try again.\n");
            }

        } else if (strcmp(args[0], "mkdir") == 0) {

			mkdir_custom(args[1]);

        } else if (strcmp(args[0], "touch") == 0) {

            touch(args[1]);

        } else if (strcmp(args[0], "exit") == 0) {

			free_args(args);
            return;
			
        } else if (strcmp(args[0], "pwd") == 0) {

			pwd();
			
		} else {

			char *command = strdup(args[0]);
			for (int i = 1; args[i] != NULL; i++) {
				printf("About to concat commands.\n");
				strcat(command, " ");
				strcat(command, args[i]);
			}
			system(command);

			free(command);

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
    loop();

    return 0;
}
