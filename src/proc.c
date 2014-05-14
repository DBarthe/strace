/*
** proc.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:59:00 2014 Barthelemy Delemotte
** Last update Wed May 14 22:20:08 2014 Barthelemy Delemotte
*/

#include	<string.h>
#include	<sys/ptrace.h>

#include	"proc.h"
#include	"strace.h"

void		proc_cleanup(t_proc *self)
{
  memset(self, 0, sizeof(t_proc));
}

void		proc_dtor(t_proc *self)
{
  if (PROCF_IS(self, PROCF_ATTACHED))
    {
      if (ptrace(PTRACE_DETACH, self->pid, 0, 0) == -1)
	{
	  tracer_print_raw("Fail to detach process %d\n", self->pid);
	}
      else
	{
	  tracer_print_raw("Process %d detached\n", self->pid);
	}
      PROCF_ZERO(self);
    }
}
