/*
** read_it.c for read_it in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Mon Jan 12 16:15:26 2015 Foyart Hugo
** Last update Sun Feb  1 21:41:53 2015 Foyart Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int	my_free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
  return (0);
}

char	**get_command(char **tab, char **path, char **envp)
{
  char	**env2;

  if (my_strcmp(tab[0], "cd") == 0 || my_strcmp(tab[0], "..") == 0)
    env2 = do_cd(tab, envp);
  else if (my_strcmp(tab[0], "setenv") == 0)
    env2 = do_setenv(tab, envp);
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    env2 = do_unset(tab, envp);
  else if ((tab[0][0] == '.' && tab[0][1] == '/') || tab[0][0] == '/')
    env2 = my_fork2(tab, envp);
  else if (my_strcmp(tab[0], "env") == 0)
    env2 = show_env(tab, envp);
  else
    {
      if (path)
	env2 = do_command(path, tab, envp);
      else
	{
	  my_puterr("Command not found: not PATH in environnement.\n");
	  return (envp);
	}
    }
  return (env2);
}

char	**cpy_env(char **env)
{
  char	**env2;
  int	i;

  i = -1;
  if ((env2 = malloc(sizeof(char *) * (count_tab(env) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (env[++i])
    {
      if ((env2[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	exit(EXIT_FAILURE);
      env2[i] = my_strcpy(env2[i], env[i]);
    }
  env2[i] = NULL;
  return (env2);
}

void	read_it(char **env)
{
  char	**tab;
  char	**path;
  char	**envp;
  char	*s;

  if (env)
    envp = cpy_env(env);
  while ((s = get_next_line(0)))
    {
      if (s[0] > 32 && s[0] < 127)
	{
	  if (get_path(envp))
	    path = my_str_to_word_tab(get_path(envp), ':');
	  else
	    path = NULL;
	  tab = my_str_to_word_tab(s, ' ');
	  if (my_strcmp(s, "exit") == 0)
	    exit(EXIT_SUCCESS);
	  envp = get_command(tab, path, envp);
	  if (path)
	    my_free_tab(path);
	}
      my_putstr("$> ");
    }
}
