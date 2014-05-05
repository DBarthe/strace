/*
** defines.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace/include
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:02:57 2014 Barthelemy Delemotte
** Last update Mon May  5 19:47:47 2014 Barthelemy Delemotte
*/

#ifndef DEFINES_H_
# define DEFINES_H_

/*
** Various defines
*/

/*
** define architectures
*/
# if __x86_64__
#  define X84_64
# elif __i386__
#  define I386
# else
#  error "unsuported architectures"
# endif /* ARCH */

/*
** maccros for debug
*/
# ifdef DEBUG
#  define IFDEBUG(inst) inst
#  define IFNDEBUG(inst)
#  include <stdio.h>
#  define DEBUG_PRINT(s) printf("#DEBUG: %s\n", s)
# else
#  define IFDEBUG(inst)
#  define IFNDEBUG(inst) inst
# endif /* DEBUG */

/*
** for unit tests
*/
# include <assert.h>

/*
** enable bool type in the whole code
*/
# include <stdbool.h>

#endif /* !DEFINES_H_ */
