#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "built_in_commands.h"
#include "input_functions.h"

/**
 * @brief Lists all files in working directory.
 *
 * Lists all files in the working directory. Equivalent to the 
 * command by the same name in bash.
 */
void ls() {
    struct dirent *entry;
    DIR *dp = opendir(".");

    if (dp == NULL) {
        printf("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
}

int cd(struct user_input *input) {
    if (input->num_tokens != 2) {
        return 1;
    }

    char *destination_dir = input->tokens[1];

    if (chdir(destination_dir) != 0) {
        return 2;
    }
    
    return 0;
}

/**
 * @brief Prints inputted string to the stdout.
 *
 * Takes a string as input, and outputs said string to the
 * stdout.
 *
 * @param[in] string String to be outputted.
 */
void echo(char *string) {
    printf("%s\n", string);
}
