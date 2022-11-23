#include "shell.h"
#include "string.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Gets length of a 2D array    
int     strlen_double(char **arr)    
{    
        int         i;    

        i = 0;    
        if (!arr || !arr[i])    
                return (0);    
        while (arr[i])    
                i++;    
        return (i);    
}    

// Checks if command is in format "cd [-P | -L | null] [ref | -]"    
char    *valid_command(char **args)    
{    
        int     i;    
        char    *option;    

        i = 0;    
        option = "";    
        if (!args)    
                return (option);    
        while (args[i] && (!strcmp(args[i], "-P") || !strcmp(args[i], "-L")))    
        {    
                if (!strcmp(args[i], "-P"))    
                        option = "-P";    
                else    
                        option = "-L";    
                i++;    
        }    
        if (args[i] && args[i][0] == '-')    
        {    
                if (args[i][1] || strlen_double(&args[i + 1]) != 0)    
                        return (NULL);    
        }    
        if (args[i] && strlen_double(&args[i]) != 1)    
                return (NULL);    
        return (option);    
}  

char    *strtrim_back(char *str, char c)
{
        int     i;
        int     iter;
        char    *res;

        iter = 0;
        i = strlen(str) - 1;
        while (str[i] && str[i] != c)
                i--;
        if (!(res = malloc(sizeof(char) * (i + 1))))
                return (NULL);
        while (iter < i)
        {
                res[iter] = str[iter];
                iter++;
        }
        res[iter] = 0;
        return (res);
}

char    *strtrim_front(char *str, char c)
{
        int     i;
        int     iter;
        char    *res;

        i = 0;
        while (str[i] && str[i] != c)
                i++;
        if (str[i])
                i++;
        if (!(res = malloc(sizeof(char) * strlen(&str[i]))))
                return (NULL);
        while (str[i])
                res[iter++] = str[i++];
        res[iter] = 0;
        return (res);
}

char	*substr(char *str, unsigned int start, char c)
{
        size_t	len;
        size_t	i;
        char	*res;

        len = 0;
        i = 0;
        while (str[len] && str[i] != c)
                len++;
        if (str[len])
                len++;
        if(!(res = malloc(sizeof(char) * (len + 1))))
                return (NULL);
        while (i < len && str[start])
        {
                res[i] = str[start];
                i++;
                start++;
        }
        res[i] = 0;
        return (res);
}

int     is_double_points(char *str)
{
        if (!strncmp(str, "..", 2))
                return (1);
        return 0;
}

int     cd_no_options(char **args)    
{    
        int         ret;
        int             len;

        len = strlen_double(args);
        switch (len)
        {
                case 0:
                        if ((ret = chdir(getenv("HOME")) < 0))
                        {
                                write(1, "Change of directory failed.\n", 28);
                                return (ret);
                        } else return (ret);
                case 1:
                        if ((ret = chdir(args[0])) < 0)
                        {
                                write(1, "Change of directory failed.\n", 28);
                                return (ret);
                        } else return (ret);
                default:
                        write(1, "You must type cd with 0 or 1 argument.\n", 39);
                        return (1);
        }
}

int     cd_l_option(char **args, char *pwd)
{
        int     len;
        int     ret;

        len = strlen_double(args) - 1;
        while (strlen(args[len]))
        {
                if (is_double_points(pwd))
                {
                        pwd = strtrim_back(pwd, '/');
                        args[len] = strtrim_front(args[len], '/');
                }
                else
                {
                        pwd = concat__(pwd, substr(args[len], 0, '/'));
                }
        }
        if (!(ret = chdir(pwd)))
                return (1);
        return (0);
}

int     cd(char **args, char *pwd)
{
        char    *option;
        int     ret;

        if (!(option = valid_command(&args[1])))
        {
                write(2, "Invalid input.\nCorrect format: 'cd [-P | -L] [ref | -]'", 56);
                return (1);
        }
        if (!strcmp(option, "-P"))
        {
                if (!(ret = chdir(pwd)))
                {
                        write(1, "Change of directory failed.\n", 28);
                        return (ret);
                } else return (ret);
        } 
        if (!strcmp(option, "-L"))
        {
                return (cd_l_option(args, pwd));
        } 
        cd_no_options(&args[1]);
        return (0);
}

