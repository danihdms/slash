#include <unistd.h>

char    *ft_pwd(void) 
{
    char    pwd[1024];

    getcwd(pwd, sizeof(pwd));
    return (pwd);
}

