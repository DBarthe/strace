/*
** proc.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:59:00 2014 Barthelemy Delemotte
** Last update Mon May  5 20:10:32 2014 Barthelemy Delemotte
*/

#include	<string.h>

#include	"proc.h"

void		proc_cleanup(t_proc *self)
{
  memset(self, 0, sizeof(t_proc));
}
