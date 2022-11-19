#include <stdio.h> // Needed for readline library
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include "strings.h"
#include "shell.h"

int main() {
	int status = 0;
	char* line = NULL, ** args = NULL;
	rl_outstream = stderr;

	while((line = readline("$> "))) {
		// {"name", "arg1", "arg2", ..., NULL}
		args = ft_split(line, ' ');
		if(args == NULL) {
			// TODO: Handle error
			status = 1;
			break;
		}

		if(args[0] != NULL) {
			if(strcmp(args[0], "exit") == 0) {
				// TODO: Handle exit command
			} else if(strcmp(args[0], "cd") == 0) {
				// TODO: Handle cd command
			} else if(strcmp(args[0], "pwd") == 0) {
				ft_pwd();
			} else {
				// TODO: Handle other commands
			}
		}

		free(line), line = NULL;
		args = ft_bigfree(args);
	}

	if(!line) free(line);
	if(!args) ft_bigfree(args);
	return status;
}
