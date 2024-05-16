#include <stdio.h>
#include <stdlib.h>

void prompt() {
    printf("> ");
}

/* This function gets input from user and uses malloc()
 * to store in input in an array of characters. 
 */
void *get_input_line() {
    char *line = malloc(sizeof(char) * 256);
    fgets(line, sizeof(line), stdin);
    return line;
}

void loop() {
    char *line;
    char **args;
    int status = 1;
}

int main(void) {
    char *line = get_input_line();
    printf("%s\n", line);
    free(line);

    return 0;
}
