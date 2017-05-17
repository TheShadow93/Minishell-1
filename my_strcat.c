/*
** my_strcat.c for my_strcat in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@epitech.net>
** 
** Started on  Sun Feb  1 15:07:16 2015 Foyart Hugo
** Last update Sun Feb  1 15:07:17 2015 Foyart Hugo
*/

#include "shell.h"

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
