/*
** strace.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 20:11:20 2014 Barthelemy Delemotte
** Last update Tue May  6 12:31:41 2014 Barthelemy Delemotte
*/

#include "strace.h"

bool		strace_init(t_tracer *tracer, t_options *opts)
{
  bool		ret;

  ret = true;
  tracer_ctor(tracer);
  if (opts->type == PROG_NAME)
    {
      tracer_print_raw(tracer, "Executing command '%s' ... ",
		       opts->prog.progname);
      tracer_flush_output(tracer);
      ret = exec_and_trace_program(tracer, opts);
      tracer_print_raw(tracer, "[OK]\n");
    }
  else
    {
      ret = attach_process(tracer, opts);
    }
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
