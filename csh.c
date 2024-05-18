#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1 
#define FALSE 0
#define MAX_BUFFER 256

/* This function prints the character indicating a user
 * should begin typing their command. 
 */
void prompt() {
    printf("> ");
}

/* Given a string. This function will output said string
 * to the standard out (most likely the terminal window).
 */
void echo(char *string) {
    printf("\"%s\"\n", string);
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

/* If the two strings are equal, returns 1 (TRUE).
 * Otherwise, returns 0 (FALSE).
 */
int are_strings_equal(char *string1, char *string2) {
    if (strstr(string1, string2) != NULL && strlen(string1) == strlen(string2)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* This function is the main loop for the shell. It gets
 * user input and executes the specified command.
 */
void loop() {
    while (TRUE) {
        prompt();
        char *line = get_input_line();

        if (are_strings_equal(line, "exit")) {
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
