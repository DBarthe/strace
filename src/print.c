/*
** print.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May  6 11:42:46 2014 Barthelemy Delemotte
** Last update Wed May 14 00:09:09 2014 Barthelemy Delemotte
*/

#include <stdarg.h>
#include <stdio.h>

#include "strace.h"

void		tracer_print_pid(t_tracer *tracer)
{
  if (tracer->tracees.length > 1 && tracer->current.pid > 0)
    {
      fprintf(stderr, "[pid %d] ", tracer->current.pid);
    }
}

void		tracer_print(t_tracer *tracer, const char *fmt, ...)
{
  va_list	ap;

  sc_print_check(tracer);
  tracer_print_pid(tracer);
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);
}

void		tracer_print_raw(const char *fmt, ...)
{
  va_list	ap;

  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);
}

void		tracer_flush_output(void)
{
  fflush(stderr);
}
