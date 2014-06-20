/*
** proc.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:59:00 2014 Barthelemy Delemotte
** Last update Sun May 18 11:05:35 2014 Barthelemy Delemotte
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
      ptrace(PTRACE_DETACH, self->pid, 0, 0);
      tracer_print_raw("Process %d detached\n", self->pid);
      PROCF_ZERO(self);
    }
}
