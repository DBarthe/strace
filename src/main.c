/*
** main.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:19:53 2014 Barthelemy Delemotte
** Last update Mon May  5 21:11:14 2014 Barthelemy Delemotte
*/

#include <stdlib.h>

#include "defines.h"
#include "proc.h"
#include "proclist.h"
#include "utils.h"

#include "strace.h"
#include "options.h"

int		main(int ac, char **av)
{
  t_options	options;
  t_tracer	tracer;
  bool		success;

  success = options_parse(&options, ac, av);
  if (success)
    {
      success = strace_init(&tracer, &options);
      if (success)
	success = strace_loop(&tracer);
      strace_quit(&tracer);
    }
  return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}
