/*
** utils.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon May  5 19:48:22 2014 Barthelemy Delemotte
** Last update Mon May  5 20:02:20 2014 Barthelemy Delemotte
*/

#ifndef UTILS_H_
# define UTILS_H_

/*
** Utils functions
*/

void	*xmalloc(size_t size);

/*
** All die- functions print a '\n'
*/
void	die(const char *s);
void	diep(const char *s);
void	dief(const char *fmt, ...);

#endif /* !UTILS_H_ */
