/*
** options.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 20:13:55 2014 Barthelemy Delemotte
** Last update Mon May  5 21:10:54 2014 Barthelemy Delemotte
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "options.h"

static bool	usage(const char *progname)
{
  fprintf(stderr, "usage: %s {-p pid | command [arg ...]}\n", progname);
  return (false);
}

static bool	options_are_valid(t_options *self)
{
  if (self->type == PROC_PID && self->proc.pid <= 0)
    {
      fprintf(stderr, "strace: error: pid must be greater than 0\n");
      return (false);
    }
  return (true);
}

bool		options_parse(t_options *self, int ac, char **av)
{
  int		opt;

  self->type = PROG_NAME;
  while ((opt = getopt(ac, av, "p:")))
    {
      if (opt == 'p')
	{
	  self->type = PROC_PID;
	  self->proc.pid = atoi(optarg);
	}
      else
	return (usage(av[0]));
    }
  if (self->type == PROG_NAME)
    {
      if (optind >= ac)
	return (usage(av[0]));
      self->prog.progname = av[optind];
      self->prog.ac = ac - optind;
      self->prog.av = av + optind;
    }
  return (options_are_valid(self));
}
