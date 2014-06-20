/*
** analyse.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May 12 14:37:35 2014 Barthelemy Delemotte
** Last update Sun May 18 11:11:53 2014 Barthelemy Delemotte
*/

#include <sys/ptrace.h>
#include <sys/wait.h>

#include "defines.h"
#include "strace.h"
#include "registers.h"

void		resolve_sig_or_group_stop(t_tracer *tracer, int *signal)
{
  siginfo_t	si;
  const char	*signame;

  signame = get_signal_name(*signal);
  if (!signame)
    {
      signame = "?";
    }
  if (ptrace(PTRACE_GETSIGINFO, tracer->current.proc->pid, 0, &si) < 0)
    {
      tracer_print(tracer, "--- stopped by %s ---\n", signame);
      *signal = 0;
    }
  else
    {
      tracer_print(tracer, "--- %s ---\n", signame);
    }
}

#if defined(I386)
static bool	distinguish_syscall(t_tracer *tracer, u_registers *regs)
{
  long int	instr;

  if (!get_instruction(tracer->current.proc, regs, &instr))
    return (false);
  return ((instr & 0xffff) == 0x80cd);
}

#elif defined(X86_64)
static bool	distinguish_syscall(t_tracer *tracer, u_registers *regs)
{
  long int	instr;
  bool		ret;

  ret = false;
  if (get_instruction(tracer->current.proc, regs, &instr))
    {
      if ((instr & 0xffff) == 0x80cd)
	{
	  DEBUG_PRINT("x86_64 syscall instruction is 'int 0x80'");
	  if (tracer->current.proc->personality == DEFAULT_PERSONALITY)
	    {
	      tracer->current.proc->personality = SECOND_PERSONALITY;
	      convert_regs_64_to_32(regs);
	    }
	  ret = true;
	}
      else if ((instr & 0xffff) == 0x050f)
	{
	  ret = true;
	}
    }
  return (ret);
}
#endif /* I386 || X86_64 */

void		analyse_current_breakpoint(t_tracer *tracer, int *signal)
{
  u_registers	regs;

  *signal = 0;
  if (!fetch_registers(tracer->current.proc, &regs))
    {
      DEBUG_PRINT("ptrace(GETREGS) has failed");
      return ;
    }
  if (PROCF_IS(tracer->current.proc, PROCF_INSYSCALL))
    {
      syscall_exit_stop(tracer, &regs);
    }
  if (distinguish_syscall(tracer, &regs) == true)
    {
      syscall_enter_stop(tracer, &regs);
    }
}
