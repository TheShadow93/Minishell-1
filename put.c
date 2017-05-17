/*
** put.c for put in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Mon Jan 12 15:20:59 2015 Foyart Hugo
** Last update Tue Jan 27 16:43:21 2015 Foyart Hugo
*/

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  if (s == NULL)
    return (0);
  while (s[i])
    i++;
  return (i);
}

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(0);
}

void	my_putstr(char *s)
{
  if (s == NULL)
    return ;
  if (write(1, s, my_strlen(s)) == -1)
    exit(0);
}

void	my_puterr(char *s)
{
  if (write(2, s, my_strlen(s)) == -1)
    exit(0);
}
