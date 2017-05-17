#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

char	*get_home(char **env)
{
  t_pt	p;
  char	*home;

  p.i = -1;
  p.j = 5;
  p.k = 0;
  if (env == NULL)
    return (NULL);
  while (env[++p.i])
    if (env[p.i][0] == 'H' && env[p.i][1] == 'O' && env[p.i][2] == 'M'
	&& env[p.i][3] == 'E' && env[p.i][4] == '=')
      {
	if ((home = malloc(sizeof(char) * (my_strlen(env[p.i] + 5) + 2))) == NULL)
	  exit(EXIT_FAILURE);
	while (env[p.i][p.j])
	  home[p.k++] = env[p.i][p.j++];
	if (home[p.k - 1] == '/')
	  home[p.k -1] = 0;
	else
	  home[p.k] = 0;
	home[p.k] = 0;
	return (home);
      }
  return (NULL);
}

char	**do_cd_default(char **env)
{
  char	**env2;

  if (get_home(env) == NULL || chdir(get_home(env)) == -1)
    {
      my_puterr("Error: cannot find or access to home.\n");
      return (env);
    }
  env2 = parse_replace_in_env(get_home(env), env);
  return (env2);
}

char	**do_cd_specified(char *s, char **env)
{
  char	*new;
  char	**env2;

  if (s[0] == '~')
    {
      if ((new = malloc(sizeof(char) *
			(my_strlen(get_home(env)) + my_strlen(s)))) == NULL)
	exit(EXIT_FAILURE);
      new = my_strcpy(new, get_home(env));
      new = my_strcat(new, s + 1);
      if (chdir(new) == -1)
	{
	  my_puterr("Error: cannot find or access to specified repository.\n");
	  return (env);
	}
      env2 = parse_replace_in_env(new, env);
      return (env2);
    }
  if (chdir(s) == -1)
    {
      my_puterr("Error: cannot find or access to specified repository.\n");
      return (env);
    }
  env2 = parse_replace_in_env(s, env);
  return (env2);
}

char	**do_cd(char **tab, char **env)
{
  char	**env2;

  if (tab[1] == NULL || my_strcmp(tab[1], "~") == 0
	   || my_strcmp(tab[1], "~/") == 0)
    env2 = do_cd_default(env);
  else if (my_strcmp(tab[0], "..") == 0)
    env2 = do_cd_specified("..", env);
  else
    env2 = do_cd_specified(tab[1], env);
  return (env2);
}
