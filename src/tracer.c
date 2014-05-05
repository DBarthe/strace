/*
** tracer.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:28:13 2014 Barthelemy Delemotte
** Last update Mon May  5 20:10:44 2014 Barthelemy Delemotte
*/

#include "strace.h"

void		tracer_ctor(t_tracer *self)
{
  proclist_ctor(&self->tracees);
}

void		tracer_dtor(t_tracer *self)
{
  proclist_dtor(&self->tracees);
}
