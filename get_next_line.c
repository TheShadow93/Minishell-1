/*
** get_next_line.c for get_next_line in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@epitech.net>
** 
** Started on  Sun Feb  1 14:38:24 2015 Foyart Hugo
** Last update Sun Feb  1 21:42:02 2015 Foyart Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

char		*get_next_line(const int fd)
{
  static char	buff[SIZE_BUF + 1];
  char		*line;
  int		ret;
  int		j;

  j = 0;
  buff[0] = 0;
  if ((ret = read(fd, buff, 32000)) == -1)
    return (NULL);
  if (buff[0] == 0)
    return (NULL);
  if ((line = malloc(sizeof(char) * (ret + 1))) == NULL)
    return (NULL);
  while (buff[j] != '\n' && buff[j])
    {
      line[j] = buff[j];
      j++;
    }
  line[j] = 0;
  return (line);
}
