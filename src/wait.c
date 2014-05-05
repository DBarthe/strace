/*
** wait.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 22:21:51 2014 Barthelemy Delemotte
** Last update Mon May  5 22:55:46 2014 Barthelemy Delemotte
*/

#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "strace.h"
#include "utils.h"

bool		wait_for_tracee(t_tracer *tracer)
{
  pid_t		pid;

  tracer_clean(tracer);
  pid = waitpid(-1, &tracer->current.status, __WALL);
  if (tracer->current.pid == -1)
    {
      if (errno == ECHILD && tracer->tracees.length == 0)
	{
	  tracer->quit = true;
	}
      else if (errno != EINTR)
	{
	  diep("waitpid");
	}
      return (false);
    }
  tracer_set_proc(tracer, (int)pid);
  return (true);
}
