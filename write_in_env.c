/*
** write_in_env.c for write_in_env in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Tue Jan 20 14:16:27 2015 Foyart Hugo
** Last update Sun Feb  1 15:24:35 2015 Foyart Hugo
*/

#include <stdlib.h>
#include "shell.h"

int	last_name(char *s)
{
  int	len;
  int	nb;

  nb = 0;
  len = my_strlen(s);
  while (s[--len] != '/')
    nb++;
  return (nb + 1);
}

char	*write_all(char *s, char *pwd)
{
  char	*env2;
  int	len;

  if ((env2 = malloc(sizeof(char) * (my_strlen(pwd) + 1))) == NULL)
    exit(EXIT_FAILURE);
  env2 = my_strcpy(env2, pwd);
  len = my_strlen(env2);
  while (env2[--len] != '=')
    env2[len] = 0;
  env2 = my_strcat(env2, s);
  return (env2);
}

char	*write_prec(char *env)
{
  char	*env2;
  int	len;

  len = my_strlen(env);
  if ((env2 = malloc(sizeof(char) * (my_strlen(env) + 1))) == NULL)
    exit(EXIT_FAILURE);
  env2 = my_strcpy(env2, env);
  if (env2[len - 1] == '/' && env[len - 2] != '=')
    env2[len--] = 0;
  while (env2[--len] != '/')
    env2[len] = 0;
  return (env2);
}

char	*write_next(char *s, char *pwd)
{
  char	*env2;

  if ((env2 = malloc(sizeof(char) *
		     (my_strlen(pwd) + my_strlen(s) + 2))) == NULL)
    exit(EXIT_FAILURE);
  env2 = my_strcpy(env2, pwd);
  env2 = my_strcat(env2, s);
  env2 = my_strcat(env2, "/");
  return (env2);
}
