#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

int	strlen_double(char **arr)
{
    int	    i;

    i = 0;
    while (arr[i])
	i++;
    return (i);
}

int	cd(char **args)
{
    int	    ret;
    int		len;

    len = strlen_double(args);
    switch (len)
    {
	case 1:
	    if ((ret = chdir(getenv("HOME")) < 0))
	    {
		    write(1, "Change of directory failed.\n", 28);
		    return (ret);
	    } else return (ret);
	case 2:
	    if ((ret = chdir(args[1])) < 0)
	    {
		    write(1, "Change of directory failed.\n", 28);
		    return (ret);
	    } else return (ret);
	default:
	    write(1, "You must type cd with 0 or 1 argument.\n", 39);
	    return (1);
    }
}

// int	main(int argc, char *argv[])
// {
//     (void) argc;
//     cd(&argv[1]);
//     return (0);
// }
