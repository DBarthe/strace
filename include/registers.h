/*
** registers.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May 12 15:48:11 2014 Barthelemy Delemotte
** Last update Tue May 13 11:55:52 2014 Barthelemy Delemotte
*/

#ifndef REGISTERS_H_
# define REGISTERS_H_

# include <sys/user.h>
# include <sys/types.h>

# include "proc.h"
# include "defines.h"

/*
** Define a 32 bits integer for i386 registers.
*/
typedef unsigned int		t_uint32;

typedef struct			__attribute__((packed))
{
  t_uint32			ebx;
  t_uint32			ecx;
  t_uint32			edx;
  t_uint32			esi;
  t_uint32			edi;
  t_uint32			ebp;
  t_uint32			eax;
  t_uint32			xds;
  t_uint32			xes;
  t_uint32			xfs;
  t_uint32			xgs;
  t_uint32			orig_eax;
  t_uint32			eip;
  t_uint32			xcs;
  t_uint32			eflags;
  t_uint32			esp;
  t_uint32			xss;
}				t_i386_user_regs_struct;

typedef union
{
  struct user_regs_struct	x86_64_r;
  t_i386_user_regs_struct	i386_r;
}				u_registers;

bool				fetch_registers(t_proc *proc,
						u_registers *regsbuf);
bool				get_instruction(t_proc *proc,
						u_registers *regs,
						long int *instr_buf);
# if defined(X86_64)
void				convert_regs_64_to_32(u_registers *regsbuf);
#endif /* X86_64 */

#endif /* !REGISTERS_H_ */
