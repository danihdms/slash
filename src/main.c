#include <stdio.h> // Needed for readline library
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include "shell.h"

int main() {
	int status = 0;
	char*	line = NULL;
	char	**args;
	rl_outstream = stderr;

	while((line = readline("$> "))) {
		// {"name", "arg1", "arg2", ..., NULL}
		args = split(line, ' ');
		if(args == NULL) {
			// TODO: Handle error
			status = 1;
			break;
		}

		if(args[0] != NULL) {
			if(strcmp(args[0], "exit") == 0) {
				if (args[1])
					return (atoi(args[1]));
				else
					return (status);
			} else if(strcmp(args[0], "cd") == 0) {
				status = cd(args);
			} else if(strcmp(args[0], "pwd") == 0) {
				status = pwd(get_pwd_adds(args + 1) );
			} else {
				// TODO: Handle other commands
			}
		}

		free(line), line = NULL;
		args = bigfree(args);
	}

	if(!line) free(line);
	if(!args) bigfree(args);
	return status;
}
