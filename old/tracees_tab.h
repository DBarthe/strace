/*
** tracees_tab.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 17:22:46 2014 Barthelemy Delemotte
** Last update Sat May  3 18:46:50 2014 Barthelemy Delemotte
*/

#ifndef				TRACEES_TAB_H_
# define			TRACEES_TAB_H_

# include			<sys/types.h>

# include			"defines.h"
# include			"tracee.h"

typedef	struct s_tracees_tab	t_tracees_tab;

struct				s_tracees_tab
{
  t_tracee			*tab;
  size_t			size;
};

/*
** initial size
*/
# define			TRACEES_TAB_INIT_SIZE	16

/*
** size of the realloc
*/
# define			TRACEES_TAB_CHUNK_SIZE	8

/*
** interface
*/
void				tracees_tab_ctor(t_tracees_tab *self);
void				tracees_tab_dtor(t_tracees_tab *self);
t_tracee			*tracees_tab_new_entry(t_tracees_tab *self);
t_tracee			*tracees_tab_get(t_tracees_tab *self,
						 pid_t pid);

#endif				/* !TRACEES_TAB_H_ */
