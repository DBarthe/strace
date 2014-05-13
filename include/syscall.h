/*
** syscall.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May 13 12:15:45 2014 Barthelemy Delemotte
** Last update Tue May 13 22:54:18 2014 Barthelemy Delemotte
*/

#ifndef SYSCALL_H_
# define SYSCALL_H_

# include "defines.h"
# include "registers.h"

# if defined(I386)
#  define MAX_NARGS	5
# elif defined(X86_64)
#  define MAX_NARGS	6
# endif /* I386 || X86_64 */

typedef struct s_sc_ent	t_sc_ent;
typedef void		(*t_sc_print)(const t_sc_ent *sc_ent,
				      const u_registers *regs);

struct			s_sc_ent
{
  const char		*name;
  unsigned int		nargs;
  t_sc_print		print_enter;
  t_sc_print		print_exit;
};

const t_sc_ent		*sc_table_get(int scno, int personality);

#endif /* !SYSCALL_H_ */
