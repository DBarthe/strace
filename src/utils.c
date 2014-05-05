/*
** utils.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/src
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:44:40 2014 Barthelemy Delemotte
** Last update Mon May  5 20:11:07 2014 Barthelemy Delemotte
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

void		die(const char *s)
{
  fprintf(stderr, "fatal error: %s\n", s);
  exit(EXIT_FAILURE);
}

void		diep(const char *s)
{
  fprintf(stderr, "fatal error: %s: %s\n", s, strerror(errno));
  exit(EXIT_FAILURE);
}

void		dief(const char *fmt, ...)
{
  va_list	ap;

  fprintf(stderr, "fatal error: ");
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);
  fprintf(stderr, "\n");
  exit(EXIT_FAILURE);
}

void		*xmalloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    dief("impossible to alloc %lu bytes\n", size);
  return (ptr);
}
