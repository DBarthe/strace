/*
** utils.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 18:35:26 2014 Barthelemy Delemotte
** Last update Sat May  3 18:36:17 2014 Barthelemy Delemotte
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<errno.h>
#include	<string.h>

void		perror_die(const char *s)
{
  fprintf(stderr, "fatal error: %s: %s\n", s, strerror(errno));
  exit(EXIT_FAILURE);
}

void		die(const char *s)
{
  fprintf(stderr, "fatal error: %s\n", s);
  exit(EXIT_FAILURE);
}
