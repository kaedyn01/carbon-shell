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
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
}

// We can assume dir is always formatted correctly for this
// function. Incorrectly formatted input will be handled in cd().
// TODO: Make entering "~" a viable command for cd. 
void cd_logic(char *destination_dir) {
    if (chdir(destination_dir) != 0) {
        perror("chdir failed\n");
        abort();
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd failed\n");
        abort();
    }
}

// TODO: Fix declaration error. 
void cd(struct user_input *input) {
    // Handle incorrect input.
    if (input->num_tokens != 2) {
        perror("incorrect number of args\n");
        return;
    }   

    cd_logic(input->tokens[1]);

    return;
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
