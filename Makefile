make: 
	gcc -Wall -Wextra -Werror built_in_commands.c input_functions.c main.c -o csh

clean: 
	rm -rf csh