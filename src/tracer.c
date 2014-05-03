/*
** tracer.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 18:50:10 2014 Barthelemy Delemotte
** Last update Sat May  3 19:26:12 2014 Barthelemy Delemotte
*/

#include		"tracer.h"

void			tracer_ctor(t_tracer *self)
{
  tracees_tab_ctor(&self->trtab);
  self->nprocs = 0;
}

void			tracer_dtor(t_tracer *self)
{
  tracees_tab_dtor(&self->trtab);
}
