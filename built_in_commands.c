#include <stdio.h>
#include <dirent.h>
#include "built_in_commands.h"

/* This function serves to add the functionality 
 * of listing all the contents of the current directory.
 * Equivalent to "ls" in bash.
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

/* Given a string. This function will output said string
 * to the standard out (most likely the terminal window).
 */
void echo(char *string) {
    printf("\"%s\"\n", string);
}
