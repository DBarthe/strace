/*
** strace.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 20:11:20 2014 Barthelemy Delemotte
** Last update Mon May  5 22:37:56 2014 Barthelemy Delemotte
*/

#include "strace.h"

bool		strace_init(t_tracer *tracer, t_options *opts)
{
  bool		ret;

  ret = true;
  tracer_ctor(tracer);
  if (opts->type == PROG_NAME)
    {
      fprintf(stderr, "Executing command '%s' ... ", opts->prog.progname);
      fflush(stderr);
      ret = exec_and_trace_program(tracer, opts);
      fprintf(stderr, "[OK]\n");
    }
  else
    {
      ret = attach_process(tracer, opts);
    }
  return (ret);
}

static void	strace_switch_status(t_tracer *tracer)
{
  if (is_status_exited(tracer))
    {

    }
}

bool		strace_loop(t_tracer *tracer)
{
  while (!tracer->quit && tracer->tracees.length > 0)
    {
      if (wait_for_tracee(tracer) == false || tracer->current.pid == 0)
	continue;
      if (tracer->current.proc == NULL)
	{
	  /* TODO: unknown pid seen */
	}
      else
	{
	  strace_switch_status(tracer);
	}
    }
  return (true);
}

void		strace_quit(t_tracer *tracer)
{
  tracer_dtor(tracer);
}
