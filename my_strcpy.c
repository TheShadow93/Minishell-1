/*
** my_strcpy.c for my_strcpy in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@epitech.net>
** 
** Started on  Tue Jan 20 14:08:23 2015 Foyart Hugo
** Last update Thu Jan 22 12:42:31 2015 Foyart Hugo
*/

#include "shell.h"

char    *my_strcpy(char *dest, char *src)
{
  int   k;

  k = 0;
  while (src[k])
    {
      dest[k] = src[k];
      k++;
    }
  dest[k] = 0;
  return (dest);
}
