/*
** proclist.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 18:56:33 2014 Barthelemy Delemotte
** Last update Mon May  5 20:10:10 2014 Barthelemy Delemotte
*/

#ifndef PROCLIST_H_
# define PROCLIST_H_

/*
** Process list
*/

# include "proc.h"

typedef struct	s_proclink	t_proclink;

struct		s_proclink
{
  t_proc	proc;
  t_proclink	*next;
  t_proclink	*prev;
};

typedef struct
{
  size_t	length;
  t_proclink	*head;
}		t_proclist;

void		proclist_ctor(t_proclist *self);
void		proclist_dtor(t_proclist *self);
t_proclink	*procslist_get(t_proclist *self, int pid);
void		proclist_rm(t_proclist *self, t_proclink *link);
t_proclink	*proclist_new(t_proclist *self);

#endif /* !PROCLIST_H_ */
