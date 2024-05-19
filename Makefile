make: 
	gcc -Wall -Wextra -Werror built_in_commands.c csh.c -o csh

clean: 
	rm -rf csh