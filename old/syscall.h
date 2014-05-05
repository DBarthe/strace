/*
** syscall.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 16:04:38 2014 Barthelemy Delemotte
** Last update Sat May  3 18:53:45 2014 Barthelemy Delemotte
*/

#ifndef				SYSCALL_H_
# define			SYSCALL_H_

# include			"defines.h"

/*
** Used to control a current syscall (see below).
*/
typedef	struct s_sc_control	t_sc_control;

/*
** Used to store constants informations about syscalls (see below).
*/
typedef struct s_sc_ent		t_sc_ent;

/*
** Max number of syscall arguments
*/
# define			SC_MAX_ARGS	6

/*
** define personalities
*/
# if			defined(X86_64)
#  define			PERSONALITIES	2
#  define			PERS0_WORDSIZE	8
#  define			PERS1_WORDSIZE	4
# elif			defined(I386)
#  define			PERSONALITIES	1
#  define			PERS0_WORDSIZE	4
# endif /* PERSONALITIES */

/*
** function called to print syscall.
*/
typedef void			(*t_syscall_enter_func)();
typedef void			(*t_syscall_exit_func)();

struct				s_sc_ent
{
  const char			*name;
  unsigned int			args_nbr;
  int				args_flags[SC_MAX_ARGS];
  int				flags;
  t_syscall_enter_func		func_enter;
  t_syscall_exit_func		func_exit;
};

struct				s_sc_control
{
  long				no;
  long				args[SC_MAX_ARGS];
  int				err_no;
  int				personality;
  const t_sc_ent		*sc_ent;
};

/*
** sc_control methodes
*/
void				sc_control_cleanup(t_sc_control *self);

/*
** sc_ent methodes
*/

/*
** syscall interface
*/

#endif /* !SYSCALL_H_ */
