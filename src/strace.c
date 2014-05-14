/*
** strace.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 20:11:20 2014 Barthelemy Delemotte
** Last update Wed May 14 22:20:48 2014 Barthelemy Delemotte
*/

#include "strace.h"

bool		strace_init(t_tracer *tracer, t_options *opts)
{
  bool		ret;

  ret = true;
  tracer_ctor(tracer);
  if (opts->type == PROG_NAME)
    {
      ret = exec_and_trace_program(tracer, opts);
    }
  else
    {
      ret = attach_process(tracer, opts);
    }
  tracer_clean(tracer);
  return (ret);
}

static void	strace_switch_status(t_tracer *tracer)
{
  if (is_exited(tracer->current.status))
    {
      tracee_exited(tracer);
    }
  else if (is_signaled(tracer->current.status))
    {
      tracee_has_been_signaled(tracer);
    }
  else if (is_ptrace_stopped(tracer->current.status))
    {
      tracee_is_ptrace_stopped(tracer);
    }
  else
    {
      tracee_is_not_stopped(tracer);
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
	}
      else
	{
	  strace_switch_status(tracer);
	}
      tracer_clean(tracer);
    }
  return (true);
}

void		strace_quit(t_tracer *tracer)
{
  tracer_dtor(tracer);
}
