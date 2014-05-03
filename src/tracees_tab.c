/*
** tracees_tab.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 17:57:45 2014 Barthelemy Delemotte
** Last update Sat May  3 18:47:49 2014 Barthelemy Delemotte
*/

#include	<stdlib.h>

#include	"tracees_tab.h"
#include	"utils.h"

void		tracees_tab_ctor(t_tracees_tab *self)
{
  size_t	i;

  self->tab = malloc(TRACEES_TAB_INIT_SIZE * sizeof(t_tracee));
  if (self->tab == NULL)
    die("insufficient memory");
  i = 0;
  while (i < TRACEES_TAB_INIT_SIZE)
    {
      tracee_cleanup(&self->tab[i]);
      i++;
    }
  self->size = TRACEES_TAB_INIT_SIZE;
}

void		tracees_tab_dtor(t_tracees_tab *self)
{
  free(self->tab);
  self->tab = NULL;
  self->size = 0;
}

