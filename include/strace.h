/*
** strace.h for strace$ in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:06:52 2014 Barthelemy Delemotte
** Last update Mon May  5 21:11:44 2014 Barthelemy Delemotte
*/

#ifndef STRACE_H_
# define STRACE_H_

/*
** The main tracer structure and algorithm
*/

# include "defines.h"
# include "proclist.h"
# include "options.h"

typedef struct
{
  t_proclist	tracees;
}		t_tracer;

void		tracer_ctor(t_tracer *self);
void		tracer_dtor(t_tracer *self);

bool		strace_init(t_tracer *tracer, t_options *opts);
bool		strace_loop(t_tracer *tracer);
void		strace_quit(t_tracer *tracer);

#endif /* !STRACE_H_ */
