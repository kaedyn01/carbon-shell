#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_functions.h"

#define MAX_BUFFER 1024

/**
 * @brief Frees all the memory allocated by interpret_input().
 *
 * This function takes an array of strings terminated by a null
 * pointer and frees all of its memory.
 *
 * @param[in] tokens The array of strings, terminated by a null\
 *      pointer, that the user wants to free from memory.
 *
 * @see interpret_input()
 */
void free_args(char **args) {
	if (args == NULL) {
		return;		// Already freed.
	}

    for(int i = 0; args[i] != NULL; i++) {
        free(args[i]);
		args[i] = NULL;	// Marks that input[i] is free.
		printf("freed one elem.\n");	// TDWD
    }
    free(args);
	args = NULL;	// Marks that input is free. 
	
	printf("args = %s\n", args == NULL ? "NULL" : "non-null"); // TDWD
}

/**
 * @brief Returns the length of a NULL terminated array.
 *
 * This function takes an array of string terminated by a NULL
 * reference and returns the length. 
 *
 * @param[in] An array of strings terminated by a NULL reference. 
 *
 * @return Length of args. 
 */
int args_len(char **args) {
    int num_args = 0;
    int i = 0;
    while(args[i] != NULL) {
        num_args++;
		i++;
    }

    return num_args;
}

/**
 * @brief Gets input and returns input as an array of arguments.
 *
 * This function takes in a line of input and converts it to 
 * an array of strings. This array is created using malloc()
 * so users will have to free the returned array.
 *
 * @return Array of strings holding args.
 */
char **get_args() {
    char *line = malloc(sizeof(char) * MAX_BUFFER);
    int num_args = 0;
    char **args = NULL;

    if (line == NULL) {
        printf("ERROR: Memroy allocation failed.\n");
        exit(1);
    }

    // Get input line.
    fgets(line, MAX_BUFFER, stdin);
    line[strcspn(line, "\n")] = '\0';

    // Count number of args.
    for (int i = 1; i < (int)strlen(line) + 1; i++) {
        if ((line[i] == ' ' && !isspace(line[i - 1])) || 
            (line[i] == '\0' && !isspace(line[i - 1]))) {
            num_args++;
        }
    }

    // Prep args. 
    args = malloc((num_args + 1) * sizeof(char *));
    args[num_args] = NULL;

    // Populate array with all of the args. 
    int b = 0;	// Beginning of substring.
    int e = 1;	// End of substring.
    int i = 0; 	// Current arg.
    while (num_args > 0) {
        if (line[e] == '\0') {
            if (!isspace(line[e - 1])) {
                int len = e - b;
                args[i] = malloc((len + 1) * sizeof(char));

                for (int j = 0; j < len; j++) {
                    args[i][j] = line[b + j];
                }
                args[i][len] = '\0';

                i++;
            }

            break;
        } else if (line[e] == ' ') {
            if (!isspace(line[e - 1])) {
                int len = e - b;
                args[i] = malloc((len + 1) * sizeof(char));

                for (int j = 0; j < len; j++) {
                    args[i][j] = line[b + j];
                }
                args[i][len] = '\0';

                i++;
            }
            
            e++;
            b = e;
        } else {
            e++;
        }
    }

	free(line);
    
    return args;
}
