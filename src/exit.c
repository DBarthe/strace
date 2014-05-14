/*
** exit.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Wed May 14 21:56:53 2014 Barthelemy Delemotte
** Last update Wed May 14 22:20:24 2014 Barthelemy Delemotte
*/

#include <stdlib.h>
#include <signal.h>

#include "strace.h"

static t_tracer		*g_tracer = NULL;

static void		exit_clean_tracer(void)
{
  if (g_tracer)
    {
      strace_quit(g_tracer);
    }
}

static void		sighandler(int signum)
{
  (void)signum;
  exit_clean_tracer();
}

void			set_exit_hook(t_tracer *tracer)
{
  g_tracer = tracer;
  signal(SIGINT, &sighandler);
}
