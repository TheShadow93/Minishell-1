

#include <stdlib.h>
#include "shell.h"

char	**do_unset(char **tab, char **env)
{
  t_pt	p;
  char	**evt;

  if (env == NULL)
    return (NULL);
  if ((p.i = detect_pos(tab[1], env)) == -1)
    return (env);
  if ((evt = malloc(sizeof(char *) * (count_tab(env)))) == NULL)
    exit(EXIT_FAILURE);
  p.j = -1;
  p.k = 0;
  while (env[++p.j])
    {
      if (p.j == p.i)
	p.j++;
      if (p.j < count_tab(env))
	{
	  if ((evt[p.k] = malloc(sizeof(char) * (my_strlen(env[p.j]) + 1))) == NULL)
	    exit(EXIT_FAILURE);
	  evt[p.k] = my_strcpy(evt[p.k], env[p.j]);
	  p.k++;
	}
    }
  evt[p.k] = NULL;
  return (evt);
}
