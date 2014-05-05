/*
** main.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:19:53 2014 Barthelemy Delemotte
** Last update Mon May  5 20:04:10 2014 Barthelemy Delemotte
*/

#include <stdlib.h>

#include "defines.h"
#include "proc.h"
#include "proclist.h"
#include "utils.h"

#include "strace.h"

int		main(void)
{
  t_tracer	tracer;
  bool		success;

  strace_init(&tracer);
  success = strace_loop(&tracer);
  strace_quit(&tracer);
  return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}
