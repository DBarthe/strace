/*
** proc.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 18:55:38 2014 Barthelemy Delemotte
** Last update Mon May  5 19:59:55 2014 Barthelemy Delemotte
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

#endif /* !PROC_H_ */
