#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "input_functions.h"

bool ls_logic_test() {
    printf(">>> Starting test for ls_logic() <<<\n");

    return true;
}

bool cd_logic_test() {
    printf(">>> Starting test for cd_logic() <<<\n");

    return true;
}

bool mkdir_logic_test() {
    printf(">>> Starting test for mkdir_logic() <<<\n");

    return true;
}

bool touch_logic_test() {
    printf(">>> Starting test for touch_logic() <<<\n");

    return true;
}

bool echo() {
    printf(">>> Starting test for echo_logic() <<<\n");

    // Send the text from stdout to file read back later. 
    freopen("test_echo.txt", "w", stdout);

    

    return true;
}

int main(void) {
    return 0;
}