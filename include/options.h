/*
** options.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 20:14:06 2014 Barthelemy Delemotte
** Last update Mon May  5 21:10:42 2014 Barthelemy Delemotte
*/

#ifndef OPTIONS_H_
# define OPTIONS_H_

# include "defines.h"

# define PROG_NAME	0
# define PROC_PID	1

typedef union
{
  int		type;
  struct
  {
    int		type;
    const char	*progname;
    int		ac;
    char	**av;
  }		prog;
  struct
  {
    int		type;
    int		pid;
  }		proc;
}		t_options;

bool		options_parse(t_options *self, int ac, char **av);

#endif /* OPTIONS_H_ */
