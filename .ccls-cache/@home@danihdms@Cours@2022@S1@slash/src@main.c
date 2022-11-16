#include <stdio.h> // Needed for readline library
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

int main() {
	int status = 0;
	char* line = NULL, ** args = NULL;

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
				exit_slash();
			} else if(strcmp(args[0], "cd") == 0) {
				// TODO: Handle cd command
			} else if(strcmp(args[0], "pwd") == 0) {
				// TODO: Handle pwd command
			} else {
				// TODO: Handle other commands
			}
		}

		free(line), line = NULL;
		free(args), args = NULL;
	}

	if(!line) free(line);
	if(!args) free(args);
	return status;
}
