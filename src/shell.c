#include <stddef.h>
#include <malloc.h>
#include "shell.h"
#include "strings.h"

char* to_fg_color(color c) {
	switch(c) {
		case BLACK: return "\001\033[0;30m\002";
		case RED: return "\001\033[0;31m\002";
		case GREEN: return "\001\033[0;32m\002";
		case YELLOW: return "\001\033[0;33m\002";
		case BLUE: return "\001\033[0;34m\002";
		case PURPLE: return "\001\033[0;35m\002";
		case CYAN: return "\001\033[0;36m\002";
		case WHITE: return "\001\033[0;37m\002";
		default: return NULL;
	}
}

char* to_bg_color(color c) {
	switch(c) {
		case BLACK: return "\001\033[0;40m\002";
		case RED: return "\001\033[0;41m\002";
		case GREEN: return "\001\033[0;42m\002";
		case YELLOW: return "\001\033[0;43m\002";
		case BLUE: return "\001\033[0;44m\002";
		case PURPLE: return "\001\033[0;45m\002";
		case CYAN: return "\001\033[0;46m\002";
		case WHITE: return "\001\033[0;47m\002";
		default: return NULL;
	}
}

shell* new_shell() {
    shell* sh = malloc(sizeof(shell));
    sh->status = 0;
    sh->owd = sh->cwd = strdup("unknown");
    shell_up_prompt(sh);
    return sh;
}

void shell_up_prompt(shell *sh) {
    free(sh->prompt);
    char *st = int_to_string(sh->status);
    char *cwd = truncate_string(sh->cwd, 30, "...");
    sh->prompt = concat(
            to_fg_color(sh->status ? RED : GREEN),
            "[", st, "]",
            RESET_COLOR,
            cwd,
            "$ "
    );
    free(st), free(cwd);
}

void shell_chcwd(shell* sh, char* cwd) {
    if(!sh || !cwd) return;
    free(sh->owd);
    sh->owd = sh->cwd;
    sh->cwd = strdup(cwd);
    shell_up_prompt(sh);
}
