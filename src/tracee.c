/*
** tracee.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May  6 11:36:46 2014 Barthelemy Delemotte
** Last update Sun May 18 11:09:16 2014 Barthelemy Delemotte
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

#include "strace.h"
#include "defines.h"

static void	remove_current_tracee(t_tracer *tracer)
{
  assert(tracer->current.proclink);
  proclist_rm(&tracer->tracees, tracer->current.proclink);
  tracer_clean(tracer);
}

void		tracee_exited(t_tracer *tracer)
{
  tracer_print(tracer, "Program exited with return code: %d\n",
	       WEXITSTATUS(tracer->current.status));
  remove_current_tracee(tracer);
}

void		tracee_has_been_signaled(t_tracer *tracer)
{
  const char	*signame;

  signame = get_signal_name(WTERMSIG(tracer->current.status));
  if (!signame)
    {
      signame = "?";
    }
  tracer_print(tracer, "+++ killed by %s +++\n", signame);
  remove_current_tracee(tracer);
}

void		tracee_is_ptrace_stopped(t_tracer *tracer)
{
  int		signal;

  signal = get_stopping_signal(tracer->current.status);
  if (signal == SIGSTOP &&
      PROCF_IS(tracer->current.proc, PROCF_IGNORE_ONE_STOP))
    {
      DEBUG_PRINT("ignoring one SIGSTOP");
      PROCF_DIS(tracer->current.proc, PROCF_IGNORE_ONE_STOP);
      signal = 0;
    }
  else if (signal != SIGTRAP)
    {
      resolve_sig_or_group_stop(tracer, &signal);
    }
  else
    {
      analyse_current_breakpoint(tracer, &signal);
    }
  (void)ptrace(PTRACE_SINGLESTEP, tracer->current.pid, tracer, signal);
}

void		tracee_is_not_stopped(t_tracer *tracer)
{
  tracer->quit = true;
  tracer_print(tracer, "error: unexpected process status\n");
}
