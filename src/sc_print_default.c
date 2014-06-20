/*
** sc_print_default.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed May 14 00:02:02 2014 Barthelemy Delemotte
** Last update Wed May 14 20:38:10 2014 Barthelemy Delemotte
*/

#include <string.h>

#include "strace.h"
#include "syscall.h"

#if defined(X86_64)
void		sc_print_enter_dfl_x86_64(const t_sc_ent *sc_ent,
					  const u_registers *regs)
{
  tracer_print_raw("%s(", sc_ent->name);
  print_args_hex_x86_64(sc_ent->nargs, regs);
  tracer_print_raw(") = ");
  tracer_flush_output();
}

void		sc_print_exit_dfl_x86_64(const t_sc_ent *sc_ent,
					 const u_registers *regs)
{
  signed long	ret;
  const char	*errno_name;

  (void)sc_ent;
  ret = (signed long)regs->x86_64_r.rax;
  if (ret >= 0)
    {
      tracer_print_raw("%lu\n", (unsigned long)ret);
    }
  else
    {
      errno_name = get_errno_name(-ret);
      tracer_print_raw("-1 %s (%s)\n", errno_name ? errno_name : "?",
		       strerror(-ret));
    }
}
#endif /* X86_64 */

#if defined(X86_64) || defined(I386)
void		sc_print_enter_dfl_i386(const t_sc_ent *sc_ent,
					const u_registers *regs)
{
  tracer_print_raw("%s(", sc_ent->name);
  print_args_hex_i386(sc_ent->nargs, regs);
  tracer_print_raw(") = ");
  tracer_flush_output();
}

void		sc_print_exit_dfl_i386(const t_sc_ent *sc_ent,
				       const u_registers *regs)
{
  signed int	ret;
  const char	*errno_name;

  (void)sc_ent;
  ret = (signed int)regs->i386_r.eax;
  if (ret >= 0)
    {
      tracer_print_raw("%u\n", (unsigned int)ret);
    }
  else
    {
      errno_name = get_errno_name(-ret);
      tracer_print_raw("-1 %s (%s)\n", errno_name ? errno_name : "?",
		       strerror(-ret));
    }
}
#endif /* X86_64 || I386 */
