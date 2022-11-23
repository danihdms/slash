#ifndef SHELL_H
#define SHELL_H

typedef struct {
    char* owd, *cwd; // old working directory, current working directory
    char* prompt;    // cached prompt (to avoid recalculating it every time)
    int status;      // exit status of last command
} shell;

shell* new_shell();

#define RESET_COLOR "\001\033[00m\002"

typedef enum {
	GREEN,
	RED,
	BLUE,
	CYAN,
	YELLOW, // or brown
	WHITE, // or gray
	BLACK,
	PURPLE,
} color;

char    *to_fg_color(color c);
char    *to_bg_color(color c);
int    	pwd(char *c);
int		cd(char **args);

#endif //SHELL_H
