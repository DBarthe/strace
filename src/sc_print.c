/*
** sc_print.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May  6 12:14:12 2014 Barthelemy Delemotte
** Last update Tue May  6 12:19:22 2014 Barthelemy Delemotte
*/

#include <stdio.h>

#include "defines.h"
#include "strace.h"

void		sc_print_check(t_tracer *tracer)
{
  if (tracer->display.pid_in_syscall > 0)
    {
      tracer->display.pid_in_syscall = 0;
      fprintf(stderr, "<unfinished ...>\n");
    }
}

void		sc_print_begin(t_tracer *tracer)
{
  assert(tracer->current.pid > 0);
  sc_print_check(tracer);
  tracer->display.pid_in_syscall = tracer->current.pid;
  tracer_print_pid(tracer);
}

void		sc_print_continue(t_tracer *tracer, const char *signame)
{
  assert(tracer->current.pid > 0);
  if (tracer->current.pid != tracer->display.pid_in_syscall)
    {
      sc_print_check(tracer);
      tracer_print_pid(tracer);
      tracer->display.pid_in_syscall = tracer->current.pid;
      fprintf(stderr, "<... %s resumed> ", signame ? signame : "");
    }
}

void		sc_print_end(t_tracer *tracer)
{
  tracer->display.pid_in_syscall = 0;
}
