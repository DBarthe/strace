/*
** proc.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 18:55:38 2014 Barthelemy Delemotte
** Last update Mon May  5 22:14:26 2014 Barthelemy Delemotte
*/

#ifndef	PROC_H_
# define PROC_H_

/*
** Process control structure
*/

typedef struct
{
  int		pid;
  int		flags;
}		t_proc;

void		proc_cleanup(t_proc *self);

/*
** .flags values and maccros:
*/
# define PROCF_ATTACHED		0x1
# define PROCF_IGNORE_ONE_STOP	0x2
# define PROCF_INSYSCALL	0x4

# define PROCF_IS(p, f)		((p)->flags & (f))
# define PROCF_ZERO(p)		((p)->flags = 0)
# define PROCF_EN(p, f)		((p)->flags |= (f))
# define PROCF_DIS(p, f)	((p)->flags &= ~(f))
# define _PROCF_INV(p, f)	PROCF_DIS(p, f) : PROCF_EN(p, f)
# define PROCF_INV(p, f)	(PROCF_IS(p, f) ? _PROCF_INV(p, f))

#endif /* !PROC_H_ */
