/*
** attach.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 21:47:16 2014 Barthelemy Delemotte
** Last update Sun May 18 11:08:31 2014 Barthelemy Delemotte
*/

#include <sys/ptrace.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "strace.h"

bool		attach_process(t_tracer *tracer, t_options *opts)
{
  if (ptrace(PTRACE_ATTACH, opts->proc.pid, 0, 0) == -1)
    {
      fprintf(stderr, "strace: call to ptrace has failed: %s\n",
	      strerror(errno));
      return (false);
    }
  tracer_set_proc(tracer, 0);
  tracer->current.proc->pid = (int)opts->proc.pid;
  PROCF_EN(tracer->current.proc, PROCF_ATTACHED);
  PROCF_EN(tracer->current.proc, PROCF_IGNORE_ONE_STOP);
  return (true);
}
