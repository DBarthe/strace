/*
** registers.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May 12 15:47:49 2014 Barthelemy Delemotte
** Last update Tue May 13 12:04:02 2014 Barthelemy Delemotte
*/

#include <sys/ptrace.h>

#include "defines.h"
#include "registers.h"

/*
** If x86_64, the current personality is found
** by looking the register cs which contains 0x23
** if the current executed code is in 32 bits mode.
**
** If we are in x86_64 with 32 bit personality, we
** have to swap some registers. Because we store
** the two versions of intel registers set in the same
** union "u_registers", these memory areas are overlapped.
** => So, the order of swaps is very important !
*/
bool		fetch_registers(t_proc *proc, u_registers *regsbuf)
{
  int		get_regs_err;

#if defined(I386)
  get_regs_err = ptrace(PTRACE_GETREGS, proc->pid, NULL, &regsbuf->i386_r);
#elif defined(X86_64)
  get_regs_err = ptrace(PTRACE_GETREGS, proc->pid, NULL, &regsbuf->x86_64_r);
  proc->personality = (regsbuf->x86_64_r.cs == 0x23 ?
		       SECOND_PERSONALITY :
		       DEFAULT_PERSONALITY);
  if (get_regs_err == 0 && proc->personality == SECOND_PERSONALITY)
    {
      proc->personality = SECOND_PERSONALITY;
      convert_regs_64_to_32(regsbuf);
    }
#endif /* I386 || X86_64 */
  return (get_regs_err == 0 ? true : false);
}

#if defined(X86_64)
void		convert_regs_64_to_32(u_registers *regsbuf)
{
  regsbuf->i386_r.ebx = regsbuf->x86_64_r.rbx;
  regsbuf->i386_r.ecx = regsbuf->x86_64_r.rcx;
  regsbuf->i386_r.edx = regsbuf->x86_64_r.rdx;
  regsbuf->i386_r.esi = regsbuf->x86_64_r.rsi;
  regsbuf->i386_r.edi = regsbuf->x86_64_r.rdi;
  regsbuf->i386_r.ebp = regsbuf->x86_64_r.rbp;
  regsbuf->i386_r.eax = regsbuf->x86_64_r.rax;
  regsbuf->i386_r.orig_eax = regsbuf->x86_64_r.orig_rax;
  regsbuf->i386_r.eip = regsbuf->x86_64_r.rip;
  regsbuf->i386_r.esp = regsbuf->x86_64_r.rsp;
}
#endif /* X86_64 */

bool		get_instruction(t_proc *proc,
				u_registers *regs,
				long int *instr_buf)
{
#if defined(I386)
  *instr_buf = ptrace(PTRACE_PEEKTEXT, proc->pid, regs->i386_r.eip, 0);
#elif defined(X86_64)
  if (proc->personality == DEFAULT_PERSONALITY)
    {
      *instr_buf = ptrace(PTRACE_PEEKTEXT, proc->pid, regs->x86_64_r.rip, 0);
    }
  else
    {
      *instr_buf = ptrace(PTRACE_PEEKTEXT, proc->pid, regs->i386_r.eip, 0);
    }
#endif /* I386 || X86_64 */
  return (*instr_buf != -1);
}
