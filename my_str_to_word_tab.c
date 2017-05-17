/*
** my_str_to_word_tab.c for my_str_to_word_tab in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Tue Jan 13 16:00:05 2015 Foyart Hugo
** Last update Sun Feb  1 14:53:15 2015 Foyart Hugo
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

int	count_words(char *s, char c)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  while (s[i])
    {
      if (s[i] == c && s[i + 1])
	nb++;
      i++;
    }
  return (nb + 1);
}

int	word_len(char *s, char c)
{
  int	i;

  i = 0;
  while (s[i] && s[i] != c)
    i++;
  return (i);
}

char	**my_str_to_word_tab(char *s, char c)
{
  char	**tb;
  t_pt	p;

  p.i = 0;
  p.j = 0;
  p.k = 0;
  if ((tb = malloc(sizeof(char *) * (count_words(s, c) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (s[p.i])
    {
      if (s[p.i] == c)
	{
	  while (s[p.i] == c)
	    p.i++;
	  p.j++;
	  p.k = 0;
	}
      if ((tb[p.j] = malloc(sizeof(char) * (word_len(s + p.i, c) + 1))) == NULL)
	exit(EXIT_FAILURE);
      while (s[p.i] != c && s[p.i])
	tb[p.j][p.k++] = s[p.i++];
      tb[p.j][p.k] = 0;
    }
  tb[p.j + 1] = 0;
  return (tb);
}

