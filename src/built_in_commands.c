#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
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
int cd(char **args) {
    if (args_len(args) != 2) {
        return 1;
    }

    char *destination_dir = args[1];

    if (chdir(destination_dir) != 0) {
        return 2;
    }
    
    return 0;
}

/**
* @brief Prints the current working directory.
*
* Prints the current working directory using getcwd().
*/
void pwd() {
   char cwd[1024];

   printf("%s\n", getcwd(cwd, sizeof(cwd)));
}

/**
 * @brief Given a directory name, makes a directory with the given name.
 *
 * Given a string dir_name representing the new directory name,
 * attempts to create a directory with that name. The new directory
 * is created and read, write, and execute permissions are given to 
 * everyone by default. If the directory creation failes, the function
 * will print an error to the stdout.
 */
void mkdir_custom(char *dir_name) {
	mode_t permissions = 0777;	// Gives everyone read, write, and execute access.
	int mkdir_result = mkdir(dir_name, permissions);

	if (mkdir_result == -1) {
		printf("Error: mkdir failed.\n");
	}
}

/**
 * @brief Creates a file named file_name. 
 *
 * This function takes the string passed to it and creates a new
 * file with that name. 
 */
void touch(char *file_name) {
	char *mode = "w+";	
	FILE *file = fopen(file_name, mode);

	fclose(file);
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
