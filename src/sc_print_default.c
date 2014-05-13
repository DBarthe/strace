/*
** sc_print_default.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed May 14 00:02:02 2014 Barthelemy Delemotte
** Last update Wed May 14 00:22:38 2014 Barthelemy Delemotte
*/

#include "strace.h"
#include "syscall.h"


#if defined(X86_64)
void		sc_print_enter_dfl_x86_64(const t_sc_ent *sc_ent,
					  const u_registers *regs)
{
  tracer_print_raw("%s(...)\t= ", sc_ent->name);
}

void		sc_print_exit_dfl_x86_64(const t_sc_ent *sc_ent,
					 const u_registers *regs)
{
  tracer_print_raw("?\n");
}
#endif /* X86_64 */


#if defined(X86_64) || defined(I386)
void		sc_print_enter_dfl_i386(const t_sc_ent *sc_ent,
					const u_registers *regs)
{
  tracer_print_raw("%s(...)\t= ", sc_ent->name);
}

void		sc_print_exit_dfl_i386(const t_sc_ent *sc_ent,
				       const u_registers *regs)
{
  tracer_print_raw("?\n");
}
#endif /* X86_64 || I386 */

