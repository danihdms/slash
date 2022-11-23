#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

#define PATH_MAX 1024

char*    pwd(shell *sh, char *c)
{
    if (strcmp(c, "-P"))
    {
        char    *pwd = calloc(PATH_MAX, sizeof(char));
        if (getcwd(pwd, PATH_MAX) != NULL) {
            shell_chstatus(sh, 0);
            return pwd;
        }
    }
    else
    {
        char *pwd;
        pwd = getenv( "PWD" );
        if (pwd) {
            shell_chstatus(sh, 0);
            return pwd;
        }
    }
    shell_chstatus(sh, 1);
    return NULL;
}

