/*
** show_env.c for show_env in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Tue Jan 20 11:07:04 2015 Foyart Hugo
** Last update Sun Feb  1 14:48:08 2015 Foyart Hugo
*/

#include <stdlib.h>
#include "shell.h"

char	**show_env(char **tab, char **env)
{
  int	i;

  i = -1;
  if (env == NULL)
    return (NULL);
  if (tab[1] != NULL)
    {
      if (my_strcmp("-0", tab[1]) == 0)
	{
	  while (env[++i])
	    my_putstr(env[i]);
	  return (env);
	}
    }
  while (env[++i])
    {
      my_putstr(env[i]);
      my_putchar('\n');
    }
  return (env);
}
