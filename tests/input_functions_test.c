#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "input_functions.h"

bool single_free_args_test(char **args) {
	char *args_elem = NULL;
	if (args != NULL) {
		args_elem = args[0];
	}

	free_args(args);
	printf("finished free_args()\n");	// TDWD

	if (args != NULL || args_elem != NULL) {
		return false;
	} else {
		return true;		
	}
} 

bool free_args_test() {
	// Init test vars.
	char **test_args = NULL;

	// Case where args is normal.
	printf("Starting case where args is normal.\n");
	test_args = malloc(3 * sizeof(char *));
	test_args[0] = strdup("cd");
	test_args[1] = strdup("/");
	test_args[2] = NULL;

	if (!single_free_args_test(test_args)) {
		return false;
	}

	// Case where args only has one element.
	printf("Starting case where args only has one element.\n");
	test_args = malloc(2 * sizeof(char *));
	test_args[0] = strdup("ls");
	test_args[1] = NULL;
	if (!single_free_args_test(test_args)) {
		return false;
	}  

	// Case where args has no elements.
	printf("Starting case where args has no elements.\n");
	test_args = malloc(sizeof(char *));
	test_args[0] = NULL;

	if (!single_free_args_test(test_args)) {
		return false;
	}

	return true;
}

bool args_len_test() {
	printf("Implement\n");	// TODO
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
	printf("free_args_test() res = %s", free_args_test() ? "true" : "false");

	return 0;	
}
