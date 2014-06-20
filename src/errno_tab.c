/*
** errno_tab.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Wed May 14 20:10:59 2014 Barthelemy Delemotte
** Last update Wed May 14 20:38:56 2014 Barthelemy Delemotte
*/

#include <stdlib.h>

static const char	*g_errno_tab[] = {
#include "errnoent.h"
};

const char		*get_errno_name(int errno)
{
  if (errno < 0 || errno >= (int)(sizeof(g_errno_tab) / sizeof(char *)))
    {
      return (NULL);
    }
  else
    {
      return (g_errno_tab[errno]);
    }
}
