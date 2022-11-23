#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

#define PATH_MAX 1024

int	pwd(char *c)
{
	char	tmp[PATH_MAX];

	if (strcmp(c, "-P"))
	{
		if (getcwd(tmp, PATH_MAX) != NULL) {
			return (0);
		}
	}
	else
	{
		char *pwd;
		pwd = getenv( "PWD" );
		if (pwd) {
			return (0);
		}
	}
	return (1);;
}

