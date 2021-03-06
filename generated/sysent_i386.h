/*
** sysent_i386.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Wed May 14 20:11:46 2014 Barthelemy Delemotte
** Last update Wed May 14 20:15:46 2014 Barthelemy Delemotte
*/

#ifndef SYSENT_I386_H
# define SYSENT_I386_H

/*
** This file has been generated by a shell script.
*/

{NULL, 0, NULL, NULL},
{"exit", 1, NULL, NULL},
{"fork", 1, NULL, NULL},
{"read", 3, NULL, NULL},
{"write", 3, NULL, NULL},
{"open", 3, NULL, NULL},
{"close", 1, NULL, NULL},
{"waitpid", 3, NULL, NULL},
{"creat", 2, NULL, NULL},
{"link", 2, NULL, NULL},
{"unlink", 1, NULL, NULL},
{"execve", 1, NULL, NULL},
{"chdir", 1, NULL, NULL},
{"time", 1, NULL, NULL},
{"mknod", 3, NULL, NULL},
{"chmod", 2, NULL, NULL},
{"lchown", 3, NULL, NULL},
{NULL, 0, NULL, NULL},
{"stat", 2, NULL, NULL},
{"lseek", 3, NULL, NULL},
{"getpid", 0, NULL, NULL},
{"mount", 3, NULL, NULL},
{"oldumount", 1, NULL, NULL},
{"setuid", 1, NULL, NULL},
{"getuid", 0, NULL, NULL},
{"stime", 1, NULL, NULL},
{"ptrace", 3, NULL, NULL},
{"alarm", 1, NULL, NULL},
{"fstat", 2, NULL, NULL},
{"pause", 0, NULL, NULL},
{"utime", 2, NULL, NULL},
{NULL, 0, NULL, NULL},
{NULL, 0, NULL, NULL},
{"access", 2, NULL, NULL},
{"nice", 1, NULL, NULL},
{NULL, 0, NULL, NULL},
{"sync", 0, NULL, NULL},
{"kill", 2, NULL, NULL},
{"rename", 2, NULL, NULL},
{"mkdir", 2, NULL, NULL},
{"rmdir", 1, NULL, NULL},
{"dup", 1, NULL, NULL},
{"pipe", 1, NULL, NULL},
{"times", 1, NULL, NULL},
{NULL, 0, NULL, NULL},
{"brk", 1, NULL, NULL},
{"setgid", 1, NULL, NULL},
{"getgid", 0, NULL, NULL},
{"signal", 2, NULL, NULL},
{"geteuid", 0, NULL, NULL},
{"getegid", 0, NULL, NULL},
{"acct", 1, NULL, NULL},
{"umount", 2, NULL, NULL},
{NULL, 0, NULL, NULL},
{"ioctl", 3, NULL, NULL},
{"fcntl", 3, NULL, NULL},
{NULL, 0, NULL, NULL},
{"setpgid", 2, NULL, NULL},
{NULL, 0, NULL, NULL},
{"olduname", 1, NULL, NULL},
{"umask", 1, NULL, NULL},
{"chroot", 1, NULL, NULL},
{"ustat", 1, NULL, NULL},
{"dup2", 1, NULL, NULL},
{"getppid", 0, NULL, NULL},
{"getpgrp", 0, NULL, NULL},
{"setsid", 0, NULL, NULL},
{"sigaction", 3, NULL, NULL},
{"sgetmask", 0, NULL, NULL},
{"ssetmask", 1, NULL, NULL},
{"setreuid", 2, NULL, NULL},
{"setregid", 2, NULL, NULL},
{"sigsuspend", 3, NULL, NULL},
{"sigpending", 1, NULL, NULL},
{"sethostname", 2, NULL, NULL},
{"setrlimit", 1, NULL, NULL},
{"getrlimit", 1, NULL, NULL},
{"getrusage", 2, NULL, NULL},
{"gettimeofday", 2, NULL, NULL},
{"settimeofday", 2, NULL, NULL},
{"getgroups", 2, NULL, NULL},
{"setgroups", 2, NULL, NULL},
{"old_select", 1, NULL, NULL},
{"symlink", 2, NULL, NULL},
{"lstat", 2, NULL, NULL},
{"readlink", 3, NULL, NULL},
{"uselib", 1, NULL, NULL},
{"swapon", 2, NULL, NULL},
{"reboot", 4, NULL, NULL},
{"old_readdir", 3, NULL, NULL},
{"old_mmap", 1, NULL, NULL},
{"munmap", 2, NULL, NULL},
{"truncate", 2, NULL, NULL},
{"ftruncate", 2, NULL, NULL},
{"fchmod", 2, NULL, NULL},
{"fchown", 3, NULL, NULL},
{"getpriority", 2, NULL, NULL},
{"setpriority", 3, NULL, NULL},
{NULL, 0, NULL, NULL},
{"statfs", 2, NULL, NULL},
{"fstatfs", 2, NULL, NULL},
{"ioperm", 2, NULL, NULL},
{"socketcall", 2, NULL, NULL},
{"syslog", 3, NULL, NULL},
{"setitimer", 3, NULL, NULL},
{"getitimer", 2, NULL, NULL},
{"newstat", 2, NULL, NULL},
{"newlstat", 2, NULL, NULL},
{"newfstat", 2, NULL, NULL},
{"uname", 1, NULL, NULL},
{"iopl", 1, NULL, NULL},
{"vhangup", 0, NULL, NULL},
{"idle", 0, NULL, NULL},
{"vm86old", 2, NULL, NULL},
{"wait4", 4, NULL, NULL},
{"swapoff", 1, NULL, NULL},
{"sysinfo", 1, NULL, NULL},
{"ipc", 5, NULL, NULL},
{"fsync", 1, NULL, NULL},
{"sigreturn", 1, NULL, NULL},
{"clone", 1, NULL, NULL},
{"setdomainname", 1, NULL, NULL},
{"newuname", 1, NULL, NULL},
{"modify_ldt", 3, NULL, NULL},
{"adjtimex", 1, NULL, NULL},
{"mprotect", 3, NULL, NULL},
{"sigprocmask", 3, NULL, NULL},
{"create_module", 2, NULL, NULL},
{"init_module", 2, NULL, NULL},
{"delete_module", 1, NULL, NULL},
{"get_kernel_syms", 1, NULL, NULL},
{"quotactl", 4, NULL, NULL},
{"getpgid", 1, NULL, NULL},
{"fchdir", 1, NULL, NULL},
{"bdflush", 2, NULL, NULL},
{"sysfs", 3, NULL, NULL},
{"personality", 1, NULL, NULL},
{NULL, 0, NULL, NULL},
{"setfsuid", 1, NULL, NULL},
{"setfsgid", 1, NULL, NULL},
{"llseek", 3, NULL, NULL},
{"getdents", 3, NULL, NULL},
{"select", 3, NULL, NULL},
{"flock", 2, NULL, NULL},
{"msync", 3, NULL, NULL},
{"readv", 2, NULL, NULL},
{"writev", 2, NULL, NULL},
{"getsid", 1, NULL, NULL},
{"fdatasync", 1, NULL, NULL},
{"sysctl", 1, NULL, NULL},
{"mlock", 2, NULL, NULL},
{"munlock", 2, NULL, NULL},
{"mlockall", 1, NULL, NULL},
{"munlockall", 0, NULL, NULL},
{"sched_setparam", 2, NULL, NULL},
{"sched_getparam", 2, NULL, NULL},
{NULL, 0, NULL, NULL},
{"sched_getscheduler", 1, NULL, NULL},
{"sched_yield", 0, NULL, NULL},
{"sched_get_priority_max", 1, NULL, NULL},
{"sched_get_priority_min", 1, NULL, NULL},
{"sched_rr_get_interval", 2, NULL, NULL},
{"nanosleep", 2, NULL, NULL},
{"mremap", 3, NULL, NULL},
{"setresuid", 3, NULL, NULL},
{"getresuid", 3, NULL, NULL},
{"vm86", 1, NULL, NULL},
{"query_module", 3, NULL, NULL},
{"poll", 3, NULL, NULL},
{"nfsservctl", 2, NULL, NULL},
{"setresgid", 3, NULL, NULL},
{"getresgid", 3, NULL, NULL},
{"prctl", 2, NULL, NULL},
{"rt_sigreturn", 1, NULL, NULL},
{"rt_sigaction", 2, NULL, NULL},
{"rt_sigprocmask", 4, NULL, NULL},
{"rt_sigpending", 2, NULL, NULL},
{"rt_sigtimedwait", 3, NULL, NULL},
{"rt_sigqueueinfo", 3, NULL, NULL},
{"rt_sigsuspend", 2, NULL, NULL},
{"pread", 3, NULL, NULL},
{"pwrite", 3, NULL, NULL},
{"chown", 2, NULL, NULL},
{"getcwd", 2, NULL, NULL},
{"capget", 2, NULL, NULL},
{"capset", 2, NULL, NULL},
{"sigaltstack", 2, NULL, NULL},
{"sendfile", 4, NULL, NULL},
{NULL, 0, NULL, NULL},
{NULL, 0, NULL, NULL},
{"vfork", 1, NULL, NULL},

#endif /* !SYSENT_I386_H */
