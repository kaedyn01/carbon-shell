#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "input_functions.h"

/**
 * @brief Tests the functionality of trim_whitespace().
 * 
 * This functions tests the functionality of trim_whitespace() in
 * input_functions.c. This function will run through the following 
 * scenarios: 
 * 
 * A normal case where there's whitespace to be trimmed.
 * 
 * A case where trimming isn't necessary.
 * 
 * A case where the input is all whitespace. 
 * 
 * A case where the input is an empty string.
 * 
 * A case where all the whitespace is in the middle of 
 * the string. 
 * 
 * A case where the input only has leading whitespace.
 * 
 * A case where the input only has trailing whitespace.
 * 
 * @return A boolean value indicating whether trim_whitespace()
 *      works.
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

	printf("Pass!\n\n");

    return true;
}

/**
 * @brief Frees the test vars allocated by interpret_input_test().
 * 
 * This helper function takes in an array of strings and a 
 * user input struct and frees them. 
 * 
 * @param[in] array The array of strings that needs to be freed. 
 * 
 * @param[in] input_struct The user_input struct that needs to be freed.
 */
static void free_test_vars(char **array, struct user_input *input_struct) {
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    free(input_struct);
}

/**
 * @brief Compares a set of values with the elements in a user_input struct.
 * 
 * This function tells the caller whether the user_input struct is correct
 * based on the values passed to the function. 
 * 
 * @param[in] correct_tokens An array of strings which is the array that 
 *      should be contained within input_struct->tokens.
 * 
 * @param[in] correct_num_tokens An integer that should match input_struct->num_tokens.
 * 
 * @param[in] correct_original_string A string that should match
 *      input_struct->original_string.
 * 
 * @param[in] input_struct The user_input struct that will be tested against 
 *      all the previous paramaters. 
 * 
 * @return A boolean value that states whether the user_input_struct is correct.
 */
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

/**
 * @brief Structure for each interpret_input() test.
 * 
 * This function takes a set of independent variables and 
 * runs a test scenario based on these variables. It then determines
 * whether interpret_input() works with the given parameters.
 * 
 * @param[in] correct_tokens The tokens that the generated user_input
 *      struct should have. 
 * 
 * @param[in] correct_num_tokens The number of tokens that should match
 *      the num_tokens field in the generated user_input struct. 
 * 
 * @param[in] correct_original_string The string that should be 
 *      contained within the original_string field within the generated
 *      user_input struct. 
 * 
 * @return A boolean value indicated whether interpret_input() passed
 *      the test with the given variables. 
 */
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
	// Handle empty input case.
	if (correct_tokens == NULL) {
		free(input_struct);
	} else {
	    free_test_vars(correct_tokens, input_struct);
	}

    return test_result;
}

/**
 * @brief Tests the functionality of interpret_input().
 * 
 * This function runs through a series of scenarios to test the 
 * functionality of interpret_input() in input_functions.c. The 
 * functions runs through the following scenarios:
 * 
 * A case where input is normal (has more than on token and
 * is formatted correctly).
 * 
 * A case where there's only one token. 
 * 
 * A case where the input is an empty string. 
 * 
 * A case where the input is only whitespace. 
 * 
 * A case where the input has no delimiters (where all the
 * valid commands and args are there but they're seperated
 * by something other than whitespace).
 * 
 * @return A boolean value indicating whether interpret_input()
 *      works correctly under all the provided scenarios. 
 */
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

	printf("Pass!\n\n");

    return true;
}

/**
 * @brief Structure for each scenario in get_input_line_test().
 * 
 * This function provides the structure for each test within 
 * get_input_line_test(). It takes a correct string that will 
 * be compared to the actual string received from get_input_line().
 * 
 * @param[in] correct_string A string that will be compared to 
 *      the value returned by get_input_line() to see if the 
 *      function behaved correctly. 
 * 
 * @return A boolean value indicating whether get_input_line()
 *      works given the provided variables. 
 */
bool single_get_input_line_test(char *correct_string) {
	char *received_string = get_input_line();

	bool result = strcmp(received_string, correct_string) == 0;
	free(received_string);
	
	return result;
}

/**
 * @brief Tests the functionality of get_input_line(). 
 * 
 * This function tests the functionality of get_input_line() defined 
 * in input_functions.c. This function will run through the following
 * scenarios: 
 * 
 * A case where input is normal. 
 * 
 * A case where the input has multiple tokens (i.e words). 
 * 
 * A case where the input is an empty string. 
 * 
 * @return A boolean indicating that get_input_line() works under all
 *      tested scenarios. 
 */
bool get_input_line_test() {
    printf(">>> Starting test for get_input_line_test() <<<\n");
	
	char *correct_string = NULL;
	
	printf("Starting case where user input is normal...\n");

	correct_string = malloc(3 * sizeof(char));
	if (correct_string == NULL) {
		printf("Failed to allocate memory in get_input_line_test().\n");
		return false;
	}
	correct_string = strdup("ls");

	if (single_get_input_line_test(correct_string) == false) {
		free(correct_string);
		return false;
	}
	free(correct_string);

	printf("Starting case where user input is multiple tokens...\n");

	correct_string = malloc(7 * sizeof(char));
	if (correct_string == NULL) {
		printf("Failed to allocate memory in get_input_line_test().\n");
		return false;
	}
	correct_string = strdup("cd dir");

	if (single_get_input_line_test(correct_string) == false) {
		free(correct_string);
		return false;
	}
	free(correct_string);

	printf("Starting case where user input is empty... \n");

	correct_string = malloc(1 * sizeof(char));
	if (correct_string == NULL) {
		printf("Failed to allocate memory in get_input_line_test().\n");
		return false;
	}
	correct_string = strdup("");

	if (single_get_input_line_test(correct_string) == false) {
		free(correct_string);
		return false;
	}
	free(correct_string);

	printf("Pass!\n\n");
    return true;
}

/**
 * @brief Calls and displays the results of all the test functions.
 * 
 * @return An integer indicating the tests ran successfully.
 */
int main(void) {
	bool trim_whitespace_result = trim_whitespace_test();
    bool interpret_input_result = interpret_input_test();
    bool get_input_line_result = get_input_line_test();
    bool all_tests_result = trim_whitespace_result &&
                            interpret_input_result &&
                            get_input_line_result;

    printf("********INPUT FUNCTIONS TEST********\n");
    printf("trim_whitespace test result:    %s\n\n", trim_whitespace_result ? "pass" : "fail");
    printf("interpret_input test result:    %s\n\n", interpret_input_result ? "pass" : "fail");
    printf("get_input_line test result:     %s\n\n", get_input_line_result ? "pass" : "fail");
    printf("ALL TESTS result:               %s\n", all_tests_result ? "pass" : "fail");

    return 0;	
}
