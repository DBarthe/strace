/*
** strace.h for strace$ in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:06:52 2014 Barthelemy Delemotte
** Last update Wed May 14 18:23:58 2014 Barthelemy Delemotte
*/

#ifndef STRACE_H_
# define STRACE_H_

/*
** The main tracer structure and functions
*/

# include "defines.h"
# include "proclist.h"
# include "options.h"
# include "registers.h"

typedef struct
{
  t_proclist	tracees;
  bool		quit;
  struct
  {
    int		pid;
    int		status;
    t_proclink	*proclink;
    t_proc	*proc;
  }		current;
  struct
  {
    int		pid_in_syscall;
  }		display;
}		t_tracer;

/*
** t_tracer "methods" :
**
** -> tracer_set_proc:	set the current working process,
**			if pid == 0, a new entry is added
**			to the proclist, if the pid does
**			not exist in the list, proc and
**			proclink are set to zero but not pid.
**
** -> tracer_clean:	cleanup current working variables
*/
void		tracer_ctor(t_tracer *self);
void		tracer_dtor(t_tracer *self);
t_proc		*tracer_set_proc(t_tracer *self, int pid);
void		tracer_clean(t_tracer *self);

/*
** strace main functions :
*/
bool		strace_init(t_tracer *tracer, t_options *opts);
bool		strace_loop(t_tracer *tracer);
void		strace_quit(t_tracer *tracer);

/*
** functions used by tracer :
*/
bool		exec_and_trace_program(t_tracer *tracer, t_options *opts);
bool		attach_process(t_tracer *tracer, t_options *opts);
bool		wait_for_tracee(t_tracer *tracer);
void		analyse_current_breakpoint(t_tracer *tracer, int *signal);
void		resolve_sig_or_group_stop(t_tracer *tracer, int *signal);
void		syscall_enter_stop(t_tracer *tracer, u_registers *registers);
void		syscall_exit_stop(t_tracer *tracer, u_registers *registers);

/*
** To exploit the process status :
*/
bool		is_exited(int status);
bool		is_signaled(int status);
bool		is_ptrace_stopped(int status);
int		get_stopping_signal(int status);

/*
** Funtions to call after having identified the process staus.
*/
void		tracee_exited(t_tracer *tracer);
void		tracee_has_been_signaled(t_tracer *tracer);
void		tracee_is_ptrace_stopped(t_tracer *tracer);
void		tracee_is_not_stopped(t_tracer *tracee);

/*
** Print utils :
*/
void		tracer_print_pid(t_tracer *tracer);
void		tracer_print(t_tracer *tracer, const char *fmt, ...);
void		tracer_print_raw(const char *fmt, ...);
void		tracer_flush_output(void);

/*
** Other print routines: specially for syscalls :
*/
void		sc_print_check(t_tracer *tracer);
void		sc_print_begin(t_tracer *tracer);
void		sc_print_continue(t_tracer *tracer, const char *signame);
void		sc_print_end(t_tracer *tracer);

#endif /* !STRACE_H_ */
