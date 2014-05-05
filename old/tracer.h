/*
** tracer.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 16:51:02 2014 Barthelemy Delemotte
** Last update Sat May  3 19:06:51 2014 Barthelemy Delemotte
*/

#ifndef			TRACER_H_
# define		TRACER_H_

# include		"defines.h"
# include		"tracees_tab.h"

/*
** the main structure.
*/
typedef struct s_tracer	t_tracer;

struct			s_tracer
{
  t_tracees_tab		trtab;
  size_t		nprocs;
};

/*
** interface
*/
void			tracer_ctor(t_tracer *self);
void			tracer_dtor(t_tracer *self);

#endif /* !TRACER_H_ */
