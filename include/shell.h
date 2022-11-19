#ifndef SHELL_H
#define SHELL_H

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

char* to_fg_color(color c);

char* to_bg_color(color c);

#endif //SHELL_H
