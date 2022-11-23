#include "../include/shell.h"
#include "../include/string.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int cd_no_options(char **args)
{
        int ret;
        int len;

        len = strlen_double(args);
        switch (len)
        {
        case 0:
                if ((ret = chdir(getenv("HOME")) < 0))
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                }
                else
		{
			getcwd(cwd, PATH_MAX);
                        return (ret);
		}
        case 1:
                if ((ret = chdir(args[0])) < 0)
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                }
                else
		{
			getcwd(cwd, PATH_MAX);
                        return (ret);
		}
        default:
                write(1, "You must type cd with 0 or 1 argument.\n", 39);
                return (1);
        }
}

int cd_l_option(char **args)
{
        int len;
        int ret;
        char    sub[PATH_MAX];

        len = strlen_double(args) - 1;
        strcpy(owd, cwd);
        strcpy(dest, args[len]);
        while (strlen(dest))
        {
                if (is_double_points(dest))
                {
                        strtrim_back('/');
                        strtrim_front('/');
                }
                else
                {
                        substr(sub, '/');
                        concat__(cwd, sub);
                        strtrim_front('/');
                }
        }
        if (!(ret = chdir(cwd)))
                return (1);
        return (0);
}

int cd(char **args)
{
        char *option;
        int ret;

        if (!(option = valid_command(&args[1])))
        {
                write(2, "Invalid input.\nCorrect format: 'cd [-P | -L] [ref | -]'", 56);
                return (1);
        }
        if (!strcmp(option, "-P"))
        {
                if (!(ret = chdir(dest)))
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                }
                else
                {
                        strcpy(owd, cwd);
                        getcwd(cwd, PATH_MAX);
                        return (ret);
                }
        }
        if (!strcmp(option, "-L"))
        {
                return (cd_l_option(args));
        }
        cd_no_options(&args[1]);
        return (0);
}
