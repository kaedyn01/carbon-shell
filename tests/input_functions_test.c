#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "input_functions.h"

bool single_args_len_test(char **args, int correct_len) {
	return args_len(args) == correct_len;
}

bool args_len_test() {
	// Init test vars.
	char **args = NULL;
	int correct_len = -1;

	// Case where args is normal.
	args = malloc(3 * sizeof(char *));
	args[0] = strdup("cd");	
	args[1] = strdup("/");	
	args[2] = NULL;

	correct_len = 2;

	if (!single_args_len_test(args, correct_len)) {
		printf("Normal case failed.\n");
		return false;
	}

	free_args(args);

	// Case where args is empty (i.e. len == 0)
	args = malloc(sizeof(char *));
	args[0] = NULL;

	correct_len = 0;

	if (!single_args_len_test(args, correct_len)) {
		printf("Case failed where args is empty.\n");
		return false;
	}

	free_args(args);
	
	// Case where args is NULL.
	args = NULL;

	correct_len = 0;

	if (!single_args_len_test(args, correct_len)) {
		printf("Case failed where args is NULL.\n");
		return false;
	}

	free_args(args);

	return true;
}

bool get_args_test() {
	printf("Implement\n");	// TODO
	return true;
}

/**
 * @brief Calls and displays the results of all the test functions.
 * 
 * @return An integer indicating the tests ran successfully.
 */
int main(void) {
	printf("args_len_test result = %s\n", args_len_test() ? "true" : "false");

	return 0;	
}
