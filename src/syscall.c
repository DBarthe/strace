/*
** syscall.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May 13 12:10:35 2014 Barthelemy Delemotte
** Last update Tue May 13 12:12:41 2014 Barthelemy Delemotte
*/

#include "strace.h"

void		syscall_enter_stop(t_tracer *tracer, u_registers *registers)
{
  DEBUG_PRINT("syscall enter");
  PROCF_EN(tracer->current.proc, PROCF_INSYSCALL);
}

void		syscall_exit_stop(t_tracer *tracer, u_registers *registers)
{
  PROCF_DIS(tracer->current.proc, PROCF_INSYSCALL);
  DEBUG_PRINT("syscall exit");
}
