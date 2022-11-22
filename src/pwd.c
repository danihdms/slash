#include <unistd.h>
#include <string.h>

int    pwd(void) 
{
    char    pwd[1024];
    int     ret;

    if (getcwd(pwd, 1024) == NULL)
        return (1);
    write(1, pwd, strlen(pwd));
    return (0);
}

