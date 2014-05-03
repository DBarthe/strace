/*
** tracee.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 15:37:43 2014 Barthelemy Delemotte
** Last update Sat May  3 20:42:18 2014 Barthelemy Delemotte
*/

#ifndef			TRACEE_H_
# define		TRACEE_H_

# include		<unistd.h>

# include		"defines.h"
# include		"syscall.h"

/*
** Used to control a tracee.
*/
typedef	struct s_tracee	t_tracee;

struct			s_tracee
{
  pid_t			pid;
  int			flags;
  int			personality;
  t_sc_control		syscall;
};

/*
** Value of t_tracee.flags
*/
# define		TRACEE_STARTUP		0x1
# define		TRACEE_IGNORE_ONE_STOP	0x2
# define		TRACEE_INSYSCALL	0x4
# define		TRACEE_ATTACHED		0x8

/*
** methodes :
*/
void			tracee_cleanup(t_tracee *self);
bool			tracee_is_free(t_tracee *self);

static inline bool	is_in_syscall(t_tracee *self)
{
  return (self->flags & TRACEE_INSYSCALL);
}

#endif			/* !TRACEE_H_ */
