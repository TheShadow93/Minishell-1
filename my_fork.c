/*
** my_fork.c for my_fork in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Wed Jan 21 11:38:00 2015 Foyart Hugo
** Last update Sun Feb  1 21:25:30 2015 Foyart Hugo
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

char	**my_fork2(char **tab, char **env)
{
  int	status;
  pid_t	pid;

  if (access(tab[0], F_OK) == -1)
    {
      my_puterr("Error: file not found.\n");
      return (env);
    }
  if ((pid = fork()) == -1)
    {
      my_puterr("Error: fork failed.\n");
      return (env);
    }
  if (pid)
    {
      if (wait(&status) == -1)
	{
	  my_puterr("Error: wait failed.\n");
	  return (env);
	}
    }
  else
    if (my_exec(tab, env) == -1)
      return (env);
  return (env);
}

int	my_fork(char **tab, char *path, char **env)
{
  int	status;
  pid_t	pid;

  if (access(path, X_OK) == -1)
    {
      my_puterr("Error: no execution right.\n");
      return (-1);
    }
  if ((pid = fork()) == -1)
    {
      my_puterr("Error: fork failed.\n");
      return (-1);
    }
  if (pid)
    {
      if (wait(&status) == -1)
	{
	  my_puterr("Error: wait failed.\n");
	  return (-1);
	}
    }
  else
    if (exec_it(tab, path, env) == -1)
      return (-1);
  return (0);
}
