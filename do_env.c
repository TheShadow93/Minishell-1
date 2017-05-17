
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

char	**write_in_new(char **tab, char **env)
{
  char	**envp;
  int	i;

  i = -1;
  if (detect_pos(tab[1], env) != -1)
    return (env);
  if ((envp = malloc(sizeof(char *) * (count_tab(env) + 3))) == NULL)
    exit(EXIT_FAILURE);
  while (++i < count_tab(env))
    if ((envp[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
      exit(EXIT_FAILURE);
  i = -1;
  while (env[++i])
    envp[i] = my_strcpy(envp[i], env[i]);
  if ((envp[i] = malloc(sizeof(char) *
			(my_strlen(tab[1]) + my_strlen(tab[2]) + 2))) == NULL)
    exit(EXIT_FAILURE);
  envp[i] = my_strcpy(envp[i], tab[1]);
  envp[i] = my_strcat(envp[i], "=");
  envp[i] = my_strcat(envp[i], tab[2]);
  envp[i + 1] = NULL;
  my_free_tab(env);
  return (envp);
}

int	detect_pos(char *s, char **env)
{
  t_pt	p;
  char	*tmp;

  p.i = -1;
  while (env[++p.i])
    {
      p.j = 0;
      p.k = 0;
      while (env[p.i][p.j] != '=')
	p.j++;
      if ((tmp = malloc(sizeof(char) * (p.j + 1))) == NULL)
	exit(EXIT_FAILURE);
      p.j = 0;
      while (env[p.i][p.j] != '=')
	tmp[p.k++] = env[p.i][p.j++];
      tmp[p.k] = 0;
      if (my_strcmp(s, tmp) == 0)
	return (p.i);
      free(tmp);
    }
  return (-1);
}

char	*cpy_line(char *evt, char **tab)
{
  evt = my_strcpy(evt, tab[1]);
  evt = my_strcat(evt, "=");
  evt = my_strcat(evt, tab[2]);
  return (evt);
}

char	**replace_in_new(char **tab, char **env)
{
  char	**evt;
  int	k;

  k = -1;
  if ((evt = malloc(sizeof(char *) * (count_tab(env) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (env[++k])
    {
      if (k == detect_pos(tab[1], env))
	{
	  if ((evt[k] = malloc(sizeof(char) * 
				 (my_strlen(tab[1]) + my_strlen(tab[2]) + 2))) == NULL)
	    exit(EXIT_FAILURE);
	  evt[k] = cpy_line(evt[k], tab);
	}
      else
	{
	  if ((evt[k] = malloc(sizeof(char) * (my_strlen(env[k]) + 1))) == NULL)
	    exit(EXIT_FAILURE);
	  evt[k] = my_strcpy(evt[k], env[k]);
	}
    }
  evt[k] = NULL;
  return (evt);
}

char	**do_setenv(char **tab, char **env)
{
  char	**envp;

  if (env == NULL)
    return (NULL);
  if (count_tab(tab) < 4)
    {
      my_puterr("Usage: setenv key value overwrite\n");
      return (env);
    }
  if (my_strcmp(tab[3], "0") == 0)
    {
      envp = write_in_new(tab, env);
      return (envp);
    }
  else if (my_strcmp(tab[3], "1") == 0)
    {
      envp = replace_in_new(tab, env);
      return (envp);
    }
  else
    {
      my_puterr("Overwrite is 0 or 1.\n");
      return (env);
    }
  return (env);
}
