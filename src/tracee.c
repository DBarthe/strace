/*
** tracee.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May  6 11:36:46 2014 Barthelemy Delemotte
** Last update Tue May  6 12:31:59 2014 Barthelemy Delemotte
*/

#include <sys/types.h>
#include <sys/wait.h>

#include "strace.h"

static void	remove_current_tracee(t_tracer *tracer)
{
  assert(tracer->current.proclink);
  proclist_rm(&tracer->tracees, tracer->current.proclink);
  tracer_clean(tracer);
}

void		tracee_exited(t_tracer *tracer)
{
  tracer_print(tracer, "Program exited with return code: %d",
	       WEXITSTATUS(tracer->current.status));
  remove_current_tracee(tracer);
}

void		tracee_has_been_signaled(t_tracer *tracer)
{
  tracer_print(tracer, "+++ killed by %d +++\n",
	       WTERMSIG(tracer->current.status));
  remove_current_tracee(tracer);
}

void		tracee_is_ptrace_stopped(t_tracer *tracer)
{
  (void)tracer;
}

void		tracee_is_not_stopped(t_tracer *tracer)
{
  tracer->quit = true;
  tracer_print(tracer, "error: excepted process status\n");
}
