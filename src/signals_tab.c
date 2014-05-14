/*
** signals_tab.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Wed May 14 20:33:07 2014 Barthelemy Delemotte
** Last update Wed May 14 20:38:27 2014 Barthelemy Delemotte
*/

#include <stdlib.h>

static const char	*g_signals_tab[] = {
#include "signalent.h"
};

const char		*get_signal_name(int signum)
{
  if (signum < 0 ||
      signum >= (int)(sizeof(g_signals_tab) / sizeof(const char *)))
    {
      return (NULL);
    }
  else
    {
      return (g_signals_tab[signum]);
    }
}
