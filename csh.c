#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0
#define MAX_BUFFER 256

void echo(char *string) {
    // TODO: Add if statement that ensures there's only one newline 
    // character at the end of the printed string. 
    printf("%s\n", string);
}

void prompt() {
    printf("> ");
}

/* This function gets input from user and uses malloc()
 * to store in input in an array of characters. 
 */
char *get_input_line() {
    char *line = malloc(sizeof(char) * MAX_BUFFER);
    fgets(line, MAX_BUFFER, stdin);
    return line;
}

void loop() {
    while (TRUE) {
        prompt();
        char *line = get_input_line();
        echo(line);
        free(line);
    }
}

int main(void) {
    
    loop();

    return 0;
}
