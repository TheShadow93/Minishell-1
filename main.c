/*
** main.c for main in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Mon Jan 12 15:18:43 2015 Foyart Hugo
** Last update Sun Feb  1 21:29:07 2015 Foyart Hugo
*/

#include <signal.h>
#include <stdlib.h>
#include "shell.h"

int	main(int ac, char **av, char **env)
{
  if (ac != 1)
    {
      my_puterr("Usage: ./mysh\n");
      return (1);
    }
  if (my_strcmp(av[0], "./mysh") != 0)
    {
      my_puterr("Usage: ./mysh\n");
      return (1);
    }
  signal(SIGINT, SIG_IGN);
  my_putstr("$> ");
  read_it(env);
  return (0);
}
