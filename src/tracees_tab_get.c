/*
** tracees_tab_get.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 18:47:20 2014 Barthelemy Delemotte
** Last update Sat May  3 18:47:46 2014 Barthelemy Delemotte
*/

#include	<stdlib.h>

#include	"tracees_tab.h"
#include	"utils.h"

static void	tracees_tab_grow(t_tracees_tab *self)
{
  size_t	new_size;
  size_t	i;

  new_size = self->size + TRACEES_TAB_CHUNK_SIZE;
  self->tab = realloc(self->tab, new_size * sizeof(t_tracee));
  if (self->tab == NULL)
    die("insufficient memory");
  i = self->size;
  while (i < new_size)
    {
      tracee_cleanup(&self->tab[i]);
      i++;
    }
  self->size = new_size;
}

static t_tracee	*tracees_tab_get_free_entry(t_tracees_tab *self)
{
  size_t	i;

  i = 0;
  while (i < self->size)
    {
      if (tracee_is_free(&self->tab[i]))
	return (&self->tab[i]);
      i++;
    }
  return (NULL);
}

t_tracee	*tracees_tab_new_entry(t_tracees_tab *self)
{
  t_tracee	*tracee;

  tracee = tracees_tab_get_free_entry(self);
  if (tracee == NULL)
    {
      size_t	size = self->size;

      tracees_tab_grow(self);
      tracee = &self->tab[size];
    }
  return (tracee);
}

t_tracee	*tracees_tab_get(t_tracees_tab *self, pid_t pid)
{
  size_t	i;

  i = 0;
  while (i < self->size)
    {
      if (self->tab[i].pid == pid)
	return (&self->tab[i]);
      i++;
    }
  return (NULL);
}
