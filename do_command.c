
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "shell.h"

int	my_exec(char **newarg, char **env)
{
  signal(SIGINT, SIG_DFL);
  if (execve(newarg[0], newarg, env) == -1)
    {
      my_puterr("Error: cannot exec file or command.\n");
      return (-1);
    }
  else
    {
      my_puterr("Error: you don't have execution rights.\n");
      return (-1);
    }
  return (0);
}

int	exec_it(char **tab, char *path, char **env)
{
  char	**newarg;
  int	i;

  i = -1;
  if ((newarg = malloc(sizeof(char *) * (count_tab(tab) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (++i < count_tab(tab))
    if ((newarg[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1))) == NULL)
      exit(EXIT_FAILURE);
  i = 0;
  newarg[0] = my_strcpy(newarg[0], path);
  while (tab[++i])
    newarg[i] = my_strcpy(newarg[i], tab[i]);
  newarg[i] = NULL;
  if (my_exec(newarg, env) == -1)
    return (-1);
  my_free_tab(newarg);
  return (0);
}

char	**do_command(char **path, char **tab, char **env)
{
  t_cmd	cmd;

  cmd.i = -1;
  while (path[++cmd.i])
    {
      if ((cmd.dirp = opendir(path[cmd.i])) == NULL)
	{
	  my_puterr(tab[0]);
	  my_puterr(" : command not found.\n");
	  return (env);
	}
      while ((cmd.read = readdir(cmd.dirp)))
	if (my_strcmp(cmd.read->d_name, tab[0]) == 0)
	  {
	    if (path[cmd.i][my_strlen(path[cmd.i]) - 1] != '/')
	      path[cmd.i] = my_strcat(path[cmd.i], "/");
	    my_fork(tab, my_strcat(path[cmd.i], tab[0]), env);
	    closedir(cmd.dirp);
	    return (env);
	  }
      if (closedir(cmd.dirp) == -1)
	return (env);
    }
  return (env);
}
