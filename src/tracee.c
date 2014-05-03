/*
** tracee.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 17:55:16 2014 Barthelemy Delemotte
** Last update Sat May  3 18:33:17 2014 Barthelemy Delemotte
*/

#include	"tracee.h"

void		tracee_cleanup(t_tracee *self)
{
  self->pid = 0;
  self->flags = 0;
  self->personality = 0;
  sc_control_cleanup(&self->syscall);
}

bool		tracee_is_free(t_tracee *self)
{
  return self->pid == 0;
}
