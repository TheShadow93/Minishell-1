/*
** get_path.c for get_path in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Mon Jan 19 15:23:56 2015 Foyart Hugo
** Last update Sun Feb  1 14:53:37 2015 Foyart Hugo
*/

#include <stdlib.h>
#include "shell.h"

char	*get_path(char **env)
{
  int	i;
  int	j;
  int	k;
  char	*path;
  
  i = -1;
  j = 5;
  k = 0;
  if (env == NULL)
    return (NULL);
  while (env[++i])
    if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
	&& env[i][3] == 'H' && env[i][4] == '=')
      {
	if ((path = malloc(sizeof(char) * (my_strlen(env[i] + 5) + 1))) == NULL)
	  exit(EXIT_FAILURE);
	while (env[i][j])
	  path[k++] = env[i][j++];
	path[k] = 0;
	return (path);
      }
  return (NULL);
}
