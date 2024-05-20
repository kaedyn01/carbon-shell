#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "input_functions.h"

// TODO: Test memory leaks from trim_whitespace().

bool trim_whitespace_test() {
    // Test normal case.
    char *untrimmed_string = "     string        ";
    char *trimmed_string = "string";
    char *returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        return false;
    }

    return true;
}

bool interpret_input_test() {
    return true;
}

bool free_tokens_test() {
    return true;
}

bool get_input_line_test() {
    return true;
}

bool prompt_test() {
    return true;
}

int main(void) {
    printf("********INPUT FUNCTIONS TEST********\n");
    printf("trim_whitespace test result:    %s\n\n", trim_whitespace_test() ? "pass" : "fail");
    printf("interpret_input test result:    %s\n\n", interpret_input_test() ? "pass" : "fail");
    printf("free_tokens test result:        %s\n\n", free_tokens_test() ? "pass" : "fail");
    printf("get_input_line test result:     %s\n\n", get_input_line_test() ? "pass" : "fail");
    printf("prompt test result:             %s\n\n", prompt_test() ? "pass" : "fail");
    printf("ALL TESTS result:               %s\n", trim_whitespace_test() &&
        interpret_input_test() &&
        free_tokens_test() &&
        get_input_line_test() &&
        trim_whitespace_test()
        ? "pass" : "fail");

    return 0;
}