#ifndef SHELL_H
#define SHELL_H

#define PATH_MAX 1024

char	owd[PATH_MAX];
char	cwd[PATH_MAX];
char	dest[PATH_MAX];
int		status = 0;

typedef struct {
    char* owd, *cwd; // old working directory, current working directory
    char* prompt;    // cached prompt (to avoid recalculating it every time)
    int status;      // exit status of last command
} shell;

shell* new_shell();

void shell_up_prompt(shell *sh);

void shell_chcwd(shell* sh, char* cwd);

void shell_chstatus(shell* sh, int status);

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
char	*pwd(shell *sh, char *c);
int		cd(char **args);

#endif //SHELL_H
