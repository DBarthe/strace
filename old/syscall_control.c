/*
** syscall_control.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 17:34:30 2014 Barthelemy Delemotte
** Last update Sat May  3 18:53:56 2014 Barthelemy Delemotte
*/

#include	<stdlib.h>
#include	<string.h>

#include	"syscall.h"

void		sc_control_cleanup(t_sc_control *self)
{
  self->no = 0;
  memset(self->args, 0, sizeof(self->args));
  self->err_no = 0;
  self->personality = 0;
  self->sc_ent = NULL;
}
