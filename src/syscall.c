/*
** syscall.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May 13 12:10:35 2014 Barthelemy Delemotte
** Last update Wed May 14 00:23:11 2014 Barthelemy Delemotte
*/

#include "strace.h"
#include "syscall.h"

static int	get_scno(t_proc *proc, u_registers *regs)
{
#if defined(I386)
  (void)proc;
  return ((int)regs->i386_r.eax);
#elif defined(X86_64)
  if (proc->personality == DEFAULT_PERSONALITY)
    {
      return ((int)regs->x86_64_r.rax);
    }
  else
    {
      return ((int)regs->i386_r.eax);
    }
#endif /* I386 || X86_64 */
}

static void	call_default_enter(t_tracer *tracer, u_registers *registers)
{
#if defined(X86_64)
  if (tracer->current.proc->personality == DEFAULT_PERSONALITY)
    {
      sc_print_enter_dfl_x86_64(tracer->current.proc->sc_ent, registers);
    }
  else
    {
      sc_print_enter_dfl_i386(tracer->current.proc->sc_ent, registers);
    }
#elif defined(I386)
  sc_print_enter_dfl_i386(tracer->current.proc->sc_ent, registers);
#endif /* I386 || X86_64 */
}

static void	call_default_exit(t_tracer *tracer, u_registers *registers)
{
#if defined(X86_64)
  if (tracer->current.proc->personality == DEFAULT_PERSONALITY)
    {
      sc_print_exit_dfl_x86_64(tracer->current.proc->sc_ent, registers);
    }
  else
    {
      sc_print_exit_dfl_i386(tracer->current.proc->sc_ent, registers);
    }
#elif defined(I386)
  sc_print_exit_dfl_i386(tracer->current.proc->sc_ent, registers);
#endif /* I386 || X86_64 */
}

void		syscall_enter_stop(t_tracer *tracer, u_registers *registers)
{
  int		scno;

  scno = get_scno(tracer->current.proc, registers);
  PROCF_EN(tracer->current.proc, PROCF_INSYSCALL);
  tracer->current.proc->sc_ent =
    sc_table_get(scno, tracer->current.proc->personality);
  if (tracer->current.proc->sc_ent)
    {
      sc_print_begin(tracer);
      if (tracer->current.proc->sc_ent->print_enter)
	{
	  tracer->current.proc->sc_ent
	    ->print_enter(tracer->current.proc->sc_ent, registers);
	}
      else
	{
	  call_default_enter(tracer, registers);
	}
      tracer_flush_output();
    }
}

void		syscall_exit_stop(t_tracer *tracer, u_registers *registers)
{
  PROCF_DIS(tracer->current.proc, PROCF_INSYSCALL);
  if (tracer->current.proc->sc_ent)
    {
      sc_print_continue(tracer, tracer->current.proc->sc_ent->name);
      if (tracer->current.proc->sc_ent->print_exit)
	{
	  tracer->current.proc->sc_ent
	    ->print_exit(tracer->current.proc->sc_ent, registers);
	}
      else
	{
	  call_default_exit(tracer, registers);
	}
      sc_print_end(tracer);
    }
}
