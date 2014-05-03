/*
** defines.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Sat May  3 15:38:33 2014 Barthelemy Delemotte
** Last update Sat May  3 17:38:50 2014 Barthelemy Delemotte
*/

#ifndef DEFINES_H_
# define DEFINES_H_

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

#endif /*! DEFINES_H_ */
