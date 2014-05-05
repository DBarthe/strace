/*
** tracer.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:28:13 2014 Barthelemy Delemotte
** Last update Mon May  5 22:54:52 2014 Barthelemy Delemotte
*/

#include <string.h>

#include "strace.h"

void		tracer_ctor(t_tracer *self)
{
  proclist_ctor(&self->tracees);
  tracer_clean(self);
}

void		tracer_dtor(t_tracer *self)
{
  proclist_dtor(&self->tracees);
}


void		tracer_clean(t_tracer *self)
{
  memset(&self->current, 0, sizeof(self->current));
}

t_proc		*tracer_set_proc(t_tracer *self, int pid)
{
  self->current.pid = pid;
  self->current.proclink = (pid == 0 ?
			    proclist_new(&self->tracees) :
			    proclist_get(&self->tracees, pid));
  self->current.proc = (self->current.proclink ?
			&self->current.proclink->proc :
			NULL);
  return (self->current.proc);
}
