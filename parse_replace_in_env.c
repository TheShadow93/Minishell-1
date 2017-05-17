/*
** parse_replace_in_env.c for parse_replace_in_env in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Tue Jan 20 12:09:33 2015 Foyart Hugo
** Last update Sun Feb  1 21:29:33 2015 Foyart Hugo
*/

#include <stdlib.h>
#include "shell.h"

char	*get_pwd(char **env)
{
  char	*pwd;
  int	i;

  i = -1;
  while (env[++i])
    if (env[i][0] == 'P' && env[i][1] == 'W'
	&& env[i][2] == 'D' && env[i][3] == '=')
      {
	if ((pwd = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	  exit(EXIT_FAILURE);
	pwd = my_strcpy(pwd, env[i]);
	if (pwd[my_strlen(pwd) - 1] != '/')
	  pwd = my_strcat(pwd, "/");
	return (pwd);
      }
  return (NULL);
}

int	calc_len(char *s)
{
  int	i;

  while (s[i] != '/' && s[i])
    i++;
  return (i);
}

char	*cpy_pwd(char *s, char *pwd, char *home)
{
  t_pt	p;
  char	*s2;
  char	*env2;

  p.i = -1;
  while (++p.i < my_strlen(s))
    {
      p.j = 0;
      if ((s2 = malloc(sizeof(char) * (calc_len(s + p.i) + 1))) == NULL)
	exit(EXIT_FAILURE);
      while (s[p.i] != '/' && s[p.i])
	s2[p.j++] = s[p.i++];
      s2[p.j] = 0;
      if (my_strcmp(s2, "..") == 0)
	pwd = write_prec(pwd);
      else if (s[p.i] == '/' && p.i == 0)
	pwd = write_all("/", pwd);
      else if (my_strcmp(s2, "~") == 0)
	pwd = write_all(home, pwd);
      else if (my_strcmp(s, ".") != 0)
	pwd = write_next(s2, pwd);
    }
  if ((env2 = malloc(sizeof(char) * (my_strlen(pwd) + 5))) == NULL)
    exit(EXIT_FAILURE);
  return ((env2 = my_strcpy(env2, pwd)));
}

char	**parse_replace_in_env(char *s, char **env)
{
  t_pt	p;
  char	**env2;
  char	*pwd;

  p.i = -1;
  if (env == NULL)
    return (NULL);
  pwd = get_pwd(env);
  if (pwd == NULL || my_strcmp(s, ".") == 0)
    return (env);
  if ((env2 = malloc(sizeof(char *) * (count_tab(env) + 2))) == NULL)
    exit(EXIT_FAILURE);
  while (env[++p.i])
    {
      if (p.i == detect_pos("PWD", env))
	env2[p.i] = cpy_pwd(s, pwd, get_home(env));
      else
	{
	  if ((env2[p.i] = malloc(sizeof(char) * (my_strlen(env[p.i]) + 1))) == NULL)
	    exit(EXIT_FAILURE);
	  env2[p.i] = my_strcpy(env2[p.i], env[p.i]);
	}
    }
  env2[p.i] = NULL;
  return (env2);
}
