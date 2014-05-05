/*
** proclist.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:31:00 2014 Barthelemy Delemotte
** Last update Mon May  5 22:53:57 2014 Barthelemy Delemotte
*/

#include <stdlib.h>

#include "proclist.h"
#include "utils.h"

void		proclist_ctor(t_proclist *self)
{
  self->length = 0;
  self->head = NULL;
}

void		proclist_dtor(t_proclist *self)
{
  t_proclink	*link;
  t_proclink	*trash;

  link = self->head;
  while (link)
    {
      trash = link;
      link = link->next;
      proclist_rm(self, trash);
    }
}

t_proclink	*proclist_get(t_proclist *self, int pid)
{
  t_proclink	*link;

  link = self->head;
  while (link)
    {
      if (link->proc.pid == pid)
	return (link);
      link = link->next;
    }
  return (NULL);
}

void		proclist_rm(t_proclist *self, t_proclink *link)
{
  if (link->prev)
    link->prev->next = link->next;
  else
    self->head = link->next;
  if (link->next)
    link->next->prev = link->prev;
  self->length -= 1;
  free(link);
}

t_proclink	*proclist_new(t_proclist *self)
{
  t_proclink	*link;

  link = xmalloc(sizeof(*link));
  link->prev = NULL;
  link->next = self->head;
  self->head = link;
  self->length += 1;
  proc_cleanup(&link->proc);
  return (link);
}
