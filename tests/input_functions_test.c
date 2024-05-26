#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "input_functions.h"

/**
 * @brief Tests the functionality of trim_whitespace().
 */
bool trim_whitespace_test() {
    printf(">>> Starting test for trim_whitespace_test() <<<\n");

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

	printf("Pass!\n");

    return true;
}

static void free_test_vars(char **array, struct user_input *input_struct) {
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    free(input_struct);
}

static bool is_user_input_struct_correct(
    char **correct_tokens, 
    int correct_num_tokens, 
    char *correct_original_string,
    struct user_input *input_struct
    ) {
    // Struct should never be null.
    if (input_struct == NULL) {
        return false;
    } 

    // Tokens should match up.
    if (correct_tokens == NULL) {
        if (correct_tokens != input_struct->tokens) {
            return false;
        }
    } else {
        for (int i = 0; correct_tokens[i] != NULL; i++) {
            if (strcmp(correct_tokens[i], input_struct->tokens[i]) != 0) {
                return false;
            }
        }
    }

    // Number of tokens and original input string should also match up.
    if (correct_num_tokens != input_struct->num_tokens) {
        return false;
    } else if (strcmp(correct_original_string, input_struct->original_string) != 0) {
        return false;
    }

    return true;
}

static bool single_interpret_input_test(
    char **correct_tokens, 
    int correct_num_tokens, 
    char *correct_original_string
    ) {
    // Construct user input struct to test.
    struct user_input *input_struct = interpret_input(correct_original_string);

    bool test_result = is_user_input_struct_correct(
        correct_tokens, 
        correct_num_tokens, 
        correct_original_string, 
        input_struct
    );

    // Free memory of test inputs that requested it in interpret_input_test().
    free_test_vars(correct_tokens, input_struct);

    return test_result;
}

bool interpret_input_test() {
    printf(">>> Starting test for interpret_input_test() <<<\n");

    // Init variables needed for each test.
    char **correct_tokens = NULL;
    int correct_num_tokens = -1;
    char *correct_original_string = NULL;

    // Test normal case.
    printf("Starting normal case...\n");

    correct_tokens = malloc(3 * sizeof(char *));
    correct_tokens[0] = strdup("echo");
    correct_tokens[1] = strdup("command");
    correct_tokens[2] = NULL;
    correct_num_tokens = 2;
    correct_original_string = "echo command";
    
    if (single_interpret_input_test(
        correct_tokens,
        correct_num_tokens,
        correct_original_string
    ) == false) {
        return false;
    }

    // Test case where there's only one token.
    printf("Starting case where there's only one token...\n");

    correct_tokens = malloc(2 * sizeof(char *));
    correct_tokens[0] = strdup("ls");
    correct_tokens[1] = NULL;
    correct_num_tokens = 1;
    correct_original_string = "ls";

    if (single_interpret_input_test(
        correct_tokens,
        correct_num_tokens,
        correct_original_string
    ) == false) {
        return false;
    }

    // Test case where input is empty string.
    printf("Starting case where input is empty string...\n");

    correct_tokens = NULL;
    correct_num_tokens = 0;
    correct_original_string = "";

    if (single_interpret_input_test(
        correct_tokens,
        correct_num_tokens,
        correct_original_string
    ) == false) {
        return false;
    }

    // Test case where input is all whitespace.
    printf("Starting case where input is all whitespace...\n");

    correct_tokens = NULL;
    correct_num_tokens = 0;
    correct_original_string = "           ";

    if (single_interpret_input_test(
        correct_tokens,
        correct_num_tokens,
        correct_original_string
    ) == false) {
        return false;
    }

    // Test case where input has no delimeters.
    printf("Starting case where input has no delimeters...\n");

    correct_tokens = malloc(2 * sizeof(char *));
    correct_tokens[0] = strdup("random-file-name");
    correct_tokens[1] = NULL;
    correct_num_tokens = 1;
    correct_original_string = "random-file-name";

    if (single_interpret_input_test(
        correct_tokens,
        correct_num_tokens,
        correct_original_string
    ) == false) {
        return false;
    }

	printf("Pass!\n");

    return true;
}

static bool single_free_tokens_test(char **input_tokens) {
	/*
	 * Change to not check for any errors but simply run
	 * as normal and let valgrind do the work to check if
	 * memory was cleared.
	 */

	return true; // Placeholder, implement function later. 
}

// Remove in favor of using Valgrind.
bool free_tokens_test() {
    printf(">>> Starting test for free_tokens_test() <<<\n");

    // Init test vars.
    int num_input_tokens = 0;
    char **input_tokens = NULL;

    // Testing normal case.
    printf("Starting normal case...\n");

    num_input_tokens = 2;
    input_tokens = malloc((num_input_tokens + 2) * sizeof(char *));
    input_tokens[0] = strdup("echo");
    input_tokens[1] = strdup("this");
    input_tokens[2] = NULL;

    if (single_free_tokens_test(input_tokens) == false) {
        return false;
    }

	printf("Check valgrind for more info...\n");

    return true;
}

bool get_input_line_test() {
    printf(">>> Starting test for get_input_line_test() <<<\n");

	printf("Pass!\n");

    return true;
}

bool prompt_test() {
    printf(">>> Starting test for prompt_test() <<<\n");

	printf("Pass!\n");

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
