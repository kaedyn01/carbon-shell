#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "input_functions.h"

bool trim_whitespace_test() {
    // Test normal case.
    printf("Starting normal case...\n");
    char *untrimmed_string = "     string        ";
    char *trimmed_string = "string";
    char *returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        printf("Error: failed normal case.\n");
        return false;
    }
    free(returned_string);

    // Test case where there's nothing to be trimmed.
    printf("Starting case where trimming isn't necessary...\n");
    untrimmed_string = "string";
    trimmed_string = "string";
    returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        printf("Error: failed case where trimming wasn't necessary.\n");
        return false;
    }
    free(returned_string);

    // Test case where the input string is all whitespace.
    printf("Starting case where string is all whitespace...\n");
    untrimmed_string = "                    ";
    trimmed_string = "";
    returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        printf("Error: failed case where string was all whitespace.\n");
        return false;
    }
    free(returned_string);

    // Test case where the input string is empty.
    printf("Starting case where input string is empty...\n");
    untrimmed_string = "";
    trimmed_string = "";
    returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        printf("Error: failed case where string was empty.\n");
        return false;
    }
    free(returned_string);

    // Test case where the input string has untrimmable whitespace.
    printf("Starting case where input string has untrimmable whitespace...\n");
    untrimmed_string = "not     trimmable";
    trimmed_string = "not     trimmable";
    returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        printf("Error: failed case where string has untrimmable whitespace.\n");
        return false;
    }
    free(returned_string);

    // Test case where the input string only has leading whitespace.
    printf("Starting case where input string has only has leading whitespace...\n");
    untrimmed_string = "   only leading";
    trimmed_string = "only leading";
    returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        printf("Error: failed case where string has only has leading whitespace.\n");
        return false;
    }
    free(returned_string);

    // Test case where the input string only has trailing whitespace.
    printf("Starting case where input string has only has trailing whitespace...\n");
    untrimmed_string = "only trailing   ";
    trimmed_string = "only trailing";
    returned_string = trim_whitespace(untrimmed_string);

    if (strcmp(trimmed_string, returned_string) != 0) {
        printf("Error: failed case where string has only has trailing whitespace.\n");
        return false;
    }
    free(returned_string);

    return true;
}

bool interpret_input_test() {
    // Test normal case.
    printf("Starting normal case...\n");

    char **correct_tokens = {"echo", "command"};
    int correct_num_tokens = 2;
    char *correct_original_string = "echo command";
    
    struct user_input *input_struct = interpret_input(correct_original_string);

    for (int i = 0; i < correct_num_tokens; i++) {
        if (strcmp(correct_tokens[i], input_struct->tokens[i]) != 0) {
            free(input_struct); // TODO: Check to see if this free is enough.
            return false;
        }
    }
    if (correct_num_tokens != input_struct->num_tokens) {
        free(input_struct);
        return false;
    } else if (strcmp(correct_original_string, input_struct->original_string) != 0) {
        free(input_struct);
        return false;
    }

    free(input_struct);

    // Test case where there's only one token.
    printf("Starting case where there's only one token...\n");

    correct_tokens = {"ls"};
    correct_num_tokens = 1;
    correct_original_string = "ls";

    input_struct = interpret_input(correct_original_string);

    if (strcmp(correct_tokens[0], input_struct->tokens[0]) != 0) {
        free(input_struct);
        return false;
    } else if (correct_num_tokens != input_struct->num_tokens) {
        free(input_struct);
        return false;
    } else if (strcmp(correct_original_string, input_struct->original_string) != 0) {
        free(input_struct);
        return false;
    }

    free(input_struct);

    // Test case where input is empty string.
    printf("Starting case where input is empty string...\n");

    correct_tokens = NULL;
    correct_num_tokens = 0;
    correct_original_string = "";

    input_struct = interpret_input(correct_original_string);

    if (correct_tokens != tokens) {
        free(input_struct);
        return false;
    } else if (correct_num_tokens != input_struct->num_tokens) {
        free(input_struct);
        return false;
    } else if (strcmp(correct_original_string, input_struct->original_string) != 0) {
        free(input_struct);
        return false;
    }

    free(input_struct);

    // Test case where input is all whitespace.
    printf("Starting case where input is all whitespace...\n");

    correct_tokens = NULL;
    correct_num_tokens = 0;
    correct_original_string = "           ";

    input_struct = interpret_input(correct_original_string);

    if (correct_tokens != tokens) {
        free(input_struct);
        return false;
    } else if (correct_num_tokens != input_struct->num_tokens) {
        free(input_struct);
        return false;
    } else if (strcmp(correct_original_string, input_struct->original_string) != 0) {
        free(input_struct);
        return false;
    }

    free(input_struct);

    // Test case where input has no delimeters.
    printf("Starting case where input has no delimeters...\n");

    correct_tokens = {"random-file-name"};
    correct_num_tokens = 1;
    correct_original_string = "random-file-name";

    input_struct = interpret_input(correct_original_string);

    if (strcmp(correct_tokens[0], input_struct->tokens[0]) != 0) {
        free(input_struct);
        return false;
    } else if (correct_num_tokens != input_struct->num_tokens) {
        free(input_struct);
        return false;
    } else if (strcmp(correct_original_string, input_struct->original_string) != 0) {
        free(input_struct);
        return false;
    }

    free(input_struct);

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
    bool trim_whitespace_result = trim_whitespace_test();
    bool interpret_input_result = interpret_input_test();
    bool free_tokens_result = free_tokens_test();
    bool get_input_line_result = get_input_line_test();
    bool prompt_result = prompt_test();
    bool all_tests_result = trim_whitespace_result &&
                            interpret_input_result &&
                            free_tokens_result &&
                            get_input_line_result && 
                            prompt_result;

    printf("********INPUT FUNCTIONS TEST********\n");
    printf("trim_whitespace test result:    %s\n\n", trim_whitespace_result ? "pass" : "fail");
    printf("interpret_input test result:    %s\n\n", interpret_input_result ? "pass" : "fail");
    printf("free_tokens test result:        %s\n\n", free_tokens_result ? "pass" : "fail");
    printf("get_input_line test result:     %s\n\n", get_input_line_result ? "pass" : "fail");
    printf("prompt test result:             %s\n\n", prompt_result ? "pass" : "fail");
    printf("ALL TESTS result:               %s\n", all_tests_result ? "pass" : "fail");

    return 0;
}