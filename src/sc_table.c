/*
** sc_table.c for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue May 13 12:15:26 2014 Barthelemy Delemotte
** Last update Tue May 13 22:54:50 2014 Barthelemy Delemotte
*/

#include <stdlib.h>

#include "syscall.h"

#if defined(X86_64)
static const t_sc_ent	g_syscall_table_x86_64[] = {
# include "sysent_x86_64.h"
};

static const t_sc_ent	*sc_table_x86_64_get(size_t scno)
{
  if (scno >= sizeof(g_syscall_table_x86_64) / sizeof(t_sc_ent)
      || g_syscall_table_x86_64[scno].name == NULL)
    {
      return (NULL);
    }
  else
    {
      return (&g_syscall_table_x86_64[scno]);
    }
}
#endif /* X86_64 */

#if defined(X86_64) || defined(I386)
static const t_sc_ent	g_syscall_table_i386[] = {
# include "sysent_i386.h"
};

const t_sc_ent		*sc_table_i386_get(size_t scno)
{
  if (scno >= sizeof(g_syscall_table_i386) / sizeof(t_sc_ent)
      || g_syscall_table_i386[scno].name == NULL)
    {
      return (NULL);
    }
  else
    {
      return (&g_syscall_table_i386[scno]);
    }
}
#endif /* X86_64 || I386 */

#if defined(X86_64)
const t_sc_ent		*sc_table_get(int scno, int personality)
{
  if (personality == DEFAULT_PERSONALITY)
    {
      return (sc_table_x86_64_get(scno));
    }
  else if (personality == SECOND_PERSONALITY)
    {
      return (sc_table_i386_get(scno));
    }
  else
    {
      return (NULL);
    }
}

#elif defined(I386)
const t_sc_ent		*sc_table_get(int scno,
				      int __attribute__((unused)) personality)
{
  return (sc_table_i386_get(scno));
}
#endif /* X86_64 */
