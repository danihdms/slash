#ifndef SHELL_H
#define SHELL_H

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
int    	pwd(void);
int		cd(char **args);

#endif //SHELL_H
