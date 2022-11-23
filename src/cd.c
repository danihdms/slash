  #include "shell.h"
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
  
  int     cd(char **args)
  {
          char    *option;
  
          if (!(option = valid_command(&args[1])))
          {
                  write(2, "Invalid input.\nCorrect format: 'cd [-P | -L] [ref | -]'", 56);
                  return (1);
          }
          cd_no_options(&args[1]);
          return (0);
  }