/*
** status.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May  6 11:14:26 2014 Barthelemy Delemotte
** Last update Mon May 12 15:01:31 2014 Barthelemy Delemotte
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "strace.h"

bool	is_exited(int status)
{
  return (WIFEXITED(status));
}

bool	is_signaled(int status)
{
  return (WIFSIGNALED(status));
}

bool	is_ptrace_stopped(int status)
{
  return (WIFSTOPPED(status));
}

int	get_stopping_signal(int status)
{
  return (WSTOPSIG(status));
}
