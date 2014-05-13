/*
** exec.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 21:22:45 2014 Barthelemy Delemotte
** Last update Wed May 14 00:21:17 2014 Barthelemy Delemotte
*/

#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "strace.h"
#include "utils.h"
#include "defines.h"

static void	exec_program(t_options *opts)
{
  ptrace(PTRACE_TRACEME, 0, 0, 0);
  raise(SIGSTOP);
  execvp(opts->prog.progname, opts->prog.av);
  dief("invalid commmand '%s': %s", opts->prog.progname, strerror(errno));
}

bool		exec_and_trace_program(t_tracer *tracer, t_options *opts)
{
  pid_t		pid;

  if ((pid = fork()) < 0)
    {
      diep("fork");
    }
  else if (pid == 0)
    {
      exec_program(opts);
      assert(false);
    }
  tracer_set_proc(tracer, 0);
  tracer->current.proc->pid = (int)pid;
  PROCF_EN(tracer->current.proc, PROCF_IGNORE_ONE_STOP);
  return (true);
}
