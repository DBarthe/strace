/*
** print_args.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Wed May 14 18:25:25 2014 Barthelemy Delemotte
** Last update Wed May 14 18:27:55 2014 Barthelemy Delemotte
*/

#include "strace.h"
#include "syscall.h"

#if defined(X86_64)
static void	print_arg_hex_x86_64(unsigned long reg, bool first)
{
  tracer_print_raw("%s0x%lx", first ? "" : ", ", reg);
}

void		print_args_hex_x86_64(unsigned int nargs,
				      const u_registers *regs)
{
  if (nargs >= 1)
    print_arg_hex_x86_64(regs->x86_64_r.rdi, true);
  if (nargs >= 2)
    print_arg_hex_x86_64(regs->x86_64_r.rsi, false);
  if (nargs >= 3)
    print_arg_hex_x86_64(regs->x86_64_r.rdx, false);
  if (nargs >= 4)
    print_arg_hex_x86_64(regs->x86_64_r.r10, false);
  if (nargs >= 5)
    print_arg_hex_x86_64(regs->x86_64_r.r8, false);
  if (nargs >= 6)
    print_arg_hex_x86_64(regs->x86_64_r.r9, false);
}
#endif /* X86_64 */

#if defined(X86_64) || defined(I386)
static void	print_arg_hex_i386(t_uint32 reg, bool first)
{
  tracer_print_raw("%s0x%x", first ? "" : ", ", reg);
}

void		print_args_hex_i386(unsigned int nargs,
				    const u_registers *regs)
{
  if (nargs >= 1)
    print_arg_hex_i386(regs->i386_r.ebx, true);
  if (nargs >= 2)
    print_arg_hex_i386(regs->i386_r.ecx, false);
  if (nargs >= 3)
    print_arg_hex_i386(regs->i386_r.edx, false);
  if (nargs >= 4)
    print_arg_hex_i386(regs->i386_r.esi, false);
  if (nargs >= 5)
    print_arg_hex_i386(regs->i386_r.edi, false);
}
#endif /* X86_64 || I386 */
