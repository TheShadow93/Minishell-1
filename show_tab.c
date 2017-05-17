/*
** show_tab.c for show_tab in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Wed Jan 21 12:03:44 2015 Foyart Hugo
** Last update Sun Feb  1 15:03:37 2015 Foyart Hugo
*/

#include "shell.h"

int     count_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
