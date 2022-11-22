#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

int    pwd(char c) 
{
    if (c == 'P')
    {
        char    pwd[1024];
        if (getcwd(pwd, 1024) == NULL)
            return (1);
        write(1, pwd, strlen(pwd));
        return (0);
    }
    else
    {
        char *pwd;
        pwd = getenv( "PWD" );
        if (!pwd)
            return (1);
        write(1, pwd, strlen(pwd));
        return (0);

    }
}

