/*
** shell.h for shell in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Foyart Hugo
** Login   <foyart_h@foyart-h>
** 
** Started on  Tue Jan 13 15:35:37 2015 Foyart Hugo
** Last update Sun Feb  1 21:43:07 2015 Foyart Hugo
*/

#ifndef SHELL_H_
# define SHELL_H_

# define SIZE_BUF 1

# include <dirent.h>

typedef struct	s_pt
{
  int		i;
  int		j;
  int		k;
}		t_pt;

typedef struct	s_cmd
{
  DIR		*dirp;
  int		i;
  struct dirent	*read;
}		t_cmd;

char	*get_next_line(const int);
char	**my_str_to_word_tab(char *, char);
int	count_words(char *, char);
int	word_len(char *, char);
void	read_it(char **);
char	**do_cd_default(char **);
char	*get_home(char **);
int	my_strcmp(char *, char *);
char	**do_cd(char **, char **);
int	my_free_tab(char **);
char	**get_command(char **, char **, char **);
char	*my_strcat(char *, char *);
char	*get_path(char **);
void	my_putstr(char *);
void	my_putchar(char);
void	my_puterr(char *);
int	my_strlen(char *);
char	*my_strcpy(char *, char *);
char	**do_command(char **, char **, char **);
int	count_tab(char **);
int	exec_it(char **, char *, char **);
int	my_exec(char **, char **);
char	**show_env(char **, char **);
char	**parse_replace_in_env(char *, char **);
char	*write_all(char *, char *);
char	*write_prec(char *);
char	*write_next(char *, char *);
char	*my_strdup(char *);
int	my_fork(char **, char *, char **);
char	**my_fork2(char **, char **);
char	**write_in_env(char **, char **);
int	detect_pos(char *, char **);
char	**replace_in_env(char **, char **);
char	**do_setenv(char **, char **);
char	**do_unset(char **, char **);
char	*exec_name(char *);
char	*cpy_pwd(char *, char *, char *);
int	last_name(char *);

#endif /* !SHELL_H_ */
