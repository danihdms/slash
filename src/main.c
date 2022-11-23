#include <stdio.h> // Needed for readline library
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include "shell.h"

int main() {
	// shell* sh = new_shell();
	char*	line = NULL;
	char	**args;
	rl_outstream = stderr;

	while((line = readline(sh->prompt))) {
		// {"name", "arg1", "arg2", ..., NULL}
		args = split(line, ' ');
		if(args == NULL) {
			// TODO: Handle error
			// sh->status = 1;
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
				char* cwd = pwd(sh, get_pwd_adds(args + 1) );
                write(STDERR_FILENO, cwd, strlen(cwd));
                if(cwd) free(cwd);
			} else {
				// TODO: Handle other commands
			}
		}

		free(line), line = NULL;
		args = bigfree(args);
	}

	if(!line) free(line);
	if(!args) bigfree(args);
	return sh->status;
}
