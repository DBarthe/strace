/*
** sysent_x86_64.h for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Wed May 14 20:11:31 2014 Barthelemy Delemotte
** Last update Sun May 18 10:46:56 2014 Barthelemy Delemotte
*/

#ifndef SYSENT_X86_64_H
# define SYSENT_X86_64_H

/*
** This file has been generated by a shell script.
*/

{"read", 3, NULL, NULL},
{"write", 3, NULL, NULL},
{"open", 2, NULL, NULL},
{"close", 1, NULL, NULL},
{"stat", 2, NULL, NULL},
{"fstat", 2, NULL, NULL},
{"lstat", 2, NULL, NULL},
{"poll", 3, NULL, NULL},
{"lseek", 2, NULL, NULL},
{"mmap", 3, NULL, NULL},
{"mprotect", 2, NULL, NULL},
{"munmap", 2, NULL, NULL},
{"brk", 1, NULL, NULL},
{"rt_sigaction", 2, NULL, NULL},
{"rt_sigprocmask", 4, NULL, NULL},
{"rt_sigreturn", 1, NULL, NULL},
{"ioctl", 2, NULL, NULL},
{"pread64", 3, NULL, NULL},
{"pwrite64", 3, NULL, NULL},
{"readv", 3, NULL, NULL},
{"writev", 3, NULL, NULL},
{"access", 2, NULL, NULL},
{"pipe", 1, NULL, NULL},
{"select", 2, NULL, NULL},
{"sched_yield", 1, NULL, NULL},
{"mremap", 1, NULL, NULL},
{"msync", 2, NULL, NULL},
{"mincore", 2, NULL, NULL},
{"madvise", 3, NULL, NULL},
{"shmget", 3, NULL, NULL},
{"shmat", 2, NULL, NULL},
{"shmctl", 3, NULL, NULL},
{"dup", 1, NULL, NULL},
{"dup2", 2, NULL, NULL},
{"pause", 1, NULL, NULL},
{"nanosleep", 1, NULL, NULL},
{"getitimer", 2, NULL, NULL},
{"alarm", 1, NULL, NULL},
{"setitimer", 3, NULL, NULL},
{"getpid", 1, NULL, NULL},
{"sendfile", 1, NULL, NULL},
{"socket", 1, NULL, NULL},
{"connect", 3, NULL, NULL},
{"accept", 3, NULL, NULL},
{"sendto", 5, NULL, NULL},
{"recvfrom", 5, NULL, NULL},
{"sendmsg", 3, NULL, NULL},
{"recvmsg", 3, NULL, NULL},
{"shutdown", 2, NULL, NULL},
{"bind", 3, NULL, NULL},
{"listen", 2, NULL, NULL},
{"getsockname", 3, NULL, NULL},
{"getpeername", 3, NULL, NULL},
{"socketpair", 3, NULL, NULL},
{"setsockopt", 5, NULL, NULL},
{"getsockopt", 5, NULL, NULL},
{"clone", 3, NULL, NULL},
{"fork", 1, NULL, NULL},
{"vfork", 1, NULL, NULL},
{"execve", 1, NULL, NULL},
{"exit", 1, NULL, NULL},
{"wait4", 2, NULL, NULL},
{"kill", 2, NULL, NULL},
{"uname", 1, NULL, NULL},
{"semget", 3, NULL, NULL},
{"semop", 3, NULL, NULL},
{"semctl", 3, NULL, NULL},
{"shmdt", 1, NULL, NULL},
{"msgget", 2, NULL, NULL},
{"msgsnd", 2, NULL, NULL},
{"msgrcv", 2, NULL, NULL},
{"msgctl", 3, NULL, NULL},
{"fcntl", 2, NULL, NULL},
{"flock", 2, NULL, NULL},
{"fsync", 1, NULL, NULL},
{"fdatasync", 1, NULL, NULL},
{"truncate", 2, NULL, NULL},
{"ftruncate", 2, NULL, NULL},
{"getdents", 2, NULL, NULL},
{"getcwd", 2, NULL, NULL},
{"chdir", 1, NULL, NULL},
{"fchdir", 1, NULL, NULL},
{"rename", 2, NULL, NULL},
{"mkdir", 2, NULL, NULL},
{"rmdir", 1, NULL, NULL},
{"creat", 2, NULL, NULL},
{"link", 2, NULL, NULL},
{"unlink", 1, NULL, NULL},
{"symlink", 2, NULL, NULL},
{"readlink", 3, NULL, NULL},
{"chmod", 2, NULL, NULL},
{"fchmod", 2, NULL, NULL},
{"chown", 3, NULL, NULL},
{"fchown", 3, NULL, NULL},
{"lchown", 3, NULL, NULL},
{"umask", 1, NULL, NULL},
{"gettimeofday", 2, NULL, NULL},
{"getrlimit", 2, NULL, NULL},
{"getrusage", 1, NULL, NULL},
{"sysinfo", 1, NULL, NULL},
{"times", 1, NULL, NULL},
{"ptrace", 2, NULL, NULL},
{"getuid", 1, NULL, NULL},
{"syslog", 1, NULL, NULL},
{"getgid", 1, NULL, NULL},
{"setuid", 1, NULL, NULL},
{"setgid", 1, NULL, NULL},
{"geteuid", 1, NULL, NULL},
{"getegid", 1, NULL, NULL},
{"setpgid", 1, NULL, NULL},
{"getppid", 1, NULL, NULL},
{"getpgrp", 1, NULL, NULL},
{"setsid", 1, NULL, NULL},
{"setreuid", 1, NULL, NULL},
{"setregid", 1, NULL, NULL},
{"getgroups", 2, NULL, NULL},
{"setgroups", 2, NULL, NULL},
{"setresuid", 3, NULL, NULL},
{"getresuid", 3, NULL, NULL},
{"setresgid", 3, NULL, NULL},
{"getresgid", 3, NULL, NULL},
{"getpgid", 1, NULL, NULL},
{"setfsuid", 1, NULL, NULL},
{"setfsgid", 1, NULL, NULL},
{"getsid", 1, NULL, NULL},
{"capget", 2, NULL, NULL},
{"capset", 2, NULL, NULL},
{"rt_sigpending", 2, NULL, NULL},
{"rt_sigtimedwait", 3, NULL, NULL},
{"rt_sigqueueinfo", 2, NULL, NULL},
{"rt_sigsuspend", 1, NULL, NULL},
{"sigaltstack", 1, NULL, NULL},
{"utime", 2, NULL, NULL},
{"mknod", 3, NULL, NULL},
{"uselib", 1, NULL, NULL},
{"personality", 1, NULL, NULL},
{"ustat", 1, NULL, NULL},
{"statfs", 2, NULL, NULL},
{"fstatfs", 2, NULL, NULL},
{"sysfs", 2, NULL, NULL},
{"getpriority", 1, NULL, NULL},
{"setpriority", 2, NULL, NULL},
{"sched_setparam", 1, NULL, NULL},
{"sched_getparam", 1, NULL, NULL},
{"sched_setscheduler", 2, NULL, NULL},
{"sched_getscheduler", 1, NULL, NULL},
{"sched_get_priority_max", 1, NULL, NULL},
{"sched_get_priority_min", 1, NULL, NULL},
{"sched_rr_get_interval", 2, NULL, NULL},
{"mlock", 2, NULL, NULL},
{"munlock", 2, NULL, NULL},
{"mlockall", 1, NULL, NULL},
{"munlockall", 1, NULL, NULL},
{"vhangup", 1, NULL, NULL},
{"modify_ldt", 1, NULL, NULL},
{"pivot_root", 2, NULL, NULL},
{"_sysctl", 1, NULL, NULL},
{"prctl", 3, NULL, NULL},
{"arch_prctl", 3, NULL, NULL},
{"adjtimex", 1, NULL, NULL},
{"setrlimit", 2, NULL, NULL},
{"chroot", 1, NULL, NULL},
{"sync", 1, NULL, NULL},
{"acct", 1, NULL, NULL},
{"settimeofday", 1, NULL, NULL},
{"mount", 3, NULL, NULL},
{"umount2", 1, NULL, NULL},
{"swapon", 1, NULL, NULL},
{"swapoff", 1, NULL, NULL},
{"reboot", 2, NULL, NULL},
{"sethostname", 1, NULL, NULL},
{"setdomainname", 1, NULL, NULL},
{"iopl", 2, NULL, NULL},
{"ioperm", 3, NULL, NULL},
{"create_module", 1, NULL, NULL},
{"init_module", 2, NULL, NULL},
{"delete_module", 2, NULL, NULL},
{"get_kernel_syms", 1, NULL, NULL},
{"query_module", 1, NULL, NULL},
{"quotactl", 2, NULL, NULL},
{"nfsservctl", 1, NULL, NULL},
{"getpmsg", 1, NULL, NULL},
{"putpmsg", 1, NULL, NULL},
{"afs_syscall", 1, NULL, NULL},
{"tuxcall", 1, NULL, NULL},
{"security", 1, NULL, NULL},
{"gettid", 1, NULL, NULL},
{"readahead", 1, NULL, NULL},
{"setxattr", 1, NULL, NULL},
{"lsetxattr", 1, NULL, NULL},
{"fsetxattr", 3, NULL, NULL},
{"getxattr", 2, NULL, NULL},
{"lgetxattr", 3, NULL, NULL},
{"fgetxattr", 4, NULL, NULL},
{"listxattr", 1, NULL, NULL},
{"llistxattr", 1, NULL, NULL},
{"flistxattr", 2, NULL, NULL},
{"removexattr", 1, NULL, NULL},
{"lremovexattr", 1, NULL, NULL},
{"fremovexattr", 2, NULL, NULL},
{"tkill", 2, NULL, NULL},
{"time", 1, NULL, NULL},
{"futex", 2, NULL, NULL},
{"sched_setaffinity", 3, NULL, NULL},
{"sched_getaffinity", 3, NULL, NULL},
{"set_thread_area", 1, NULL, NULL},
{"io_setup", 2, NULL, NULL},
{"io_destroy", 1, NULL, NULL},
{"io_getevents", 2, NULL, NULL},
{"io_submit", 3, NULL, NULL},
{"io_cancel", 2, NULL, NULL},
{"get_thread_area", 1, NULL, NULL},
{"lookup_dcookie", 2, NULL, NULL},
{"epoll_create", 1, NULL, NULL},
{"epoll_ctl_old", 1, NULL, NULL},
{"epoll_wait_old", 1, NULL, NULL},
{"remap_file_pages", 2, NULL, NULL},
{"getdents64", 2, NULL, NULL},
{"set_tid_address", 1, NULL, NULL},
{"restart_syscall", 1, NULL, NULL},
{"semtimedop", 1, NULL, NULL},
{"fadvise64", 3, NULL, NULL},
{"timer_create", 2, NULL, NULL},
{"timer_settime", 4, NULL, NULL},
{"timer_gettime", 2, NULL, NULL},
{"timer_getoverrun", 1, NULL, NULL},
{"timer_delete", 1, NULL, NULL},
{"clock_settime", 2, NULL, NULL},
{"clock_gettime", 2, NULL, NULL},
{"clock_getres", 2, NULL, NULL},
{"clock_nanosleep", 3, NULL, NULL},
{"exit_group", 1, NULL, NULL},
{"epoll_wait", 2, NULL, NULL},
{"epoll_ctl", 3, NULL, NULL},
{"tgkill", 2, NULL, NULL},
{"utimes", 2, NULL, NULL},
{"vserver", 1, NULL, NULL},
{"mbind", 2, NULL, NULL},
{"set_mempolicy", 2, NULL, NULL},
{"get_mempolicy", 4, NULL, NULL},
{"mq_open", 4, NULL, NULL},
{"mq_unlink", 1, NULL, NULL},
{"mq_timedsend", 2, NULL, NULL},
{"mq_timedreceive", 4, NULL, NULL},
{"mq_notify", 2, NULL, NULL},
{"mq_getsetattr", 3, NULL, NULL},
{"kexec_load", 3, NULL, NULL},
{"waitid", 4, NULL, NULL},
{"add_key", 3, NULL, NULL},
{"keyctl", 5, NULL, NULL},
{"ioprio_set", 2, NULL, NULL},
{"ioprio_get", 2, NULL, NULL},
{"inotify_init", 1, NULL, NULL},
{"inotify_add_watch", 1, NULL, NULL},
{"inotify_rm_watch", 2, NULL, NULL},
{"migrate_pages", 2, NULL, NULL},
{"openat", 2, NULL, NULL},
{"mkdirat", 2, NULL, NULL},
{"mknodat", 3, NULL, NULL},
{"fchownat", 3, NULL, NULL},
{"futimesat", 2, NULL, NULL},
{"newfstatat", 3, NULL, NULL},
{"unlinkat", 2, NULL, NULL},
{"renameat", 3, NULL, NULL},
{"linkat", 3, NULL, NULL},
{"symlinkat", 3, NULL, NULL},
{"readlinkat", 2, NULL, NULL},
{"fchmodat", 2, NULL, NULL},
{"faccessat", 2, NULL, NULL},
{"pselect6", 4, NULL, NULL},
{"ppoll", 4, NULL, NULL},
{"unshare", 1, NULL, NULL},
{"set_robust_list", 2, NULL, NULL},
{"get_robust_list", 3, NULL, NULL},
{"splice", 4, NULL, NULL},
{"tee", 4, NULL, NULL},
{"sync_file_range", 4, NULL, NULL},
{"vmsplice", 3, NULL, NULL},
{"move_pages", 5, NULL, NULL},
{"utimensat", 4, NULL, NULL},
{"epoll_pwait", 5, NULL, NULL},
{"signalfd", 3, NULL, NULL},
{"timerfd_create", 2, NULL, NULL},
{"eventfd", 1, NULL, NULL},
{"fallocate", 2, NULL, NULL},
{"timerfd_settime", 2, NULL, NULL},
{"timerfd_gettime", 1, NULL, NULL},
{"accept4", 3, NULL, NULL},
{"signalfd4", 3, NULL, NULL},
{"eventfd2", 2, NULL, NULL},
{"epoll_create1", 1, NULL, NULL},
{"dup3", 2, NULL, NULL},
{"pipe2", 1, NULL, NULL},
{"inotify_init1", 1, NULL, NULL},
{"preadv", 2, NULL, NULL},
{"pwritev", 2, NULL, NULL},
{"rt_tgsigqueueinfo", 3, NULL, NULL},
{"perf_event_open", 4, NULL, NULL},
{"recvmmsg", 5, NULL, NULL},
{"fanotify_init", 1, NULL, NULL},
{"fanotify_mark", 2, NULL, NULL},
{"prlimit64", 3, NULL, NULL},
{"name_to_handle_at", 4, NULL, NULL},
{"open_by_handle_at", 3, NULL, NULL},
{"clock_adjtime", 2, NULL, NULL},
{"syncfs", 1, NULL, NULL},
{"sendmmsg", 2, NULL, NULL},
{"setns", 2, NULL, NULL},
{"getcpu", 3, NULL, NULL},
{"process_vm_readv", 4, NULL, NULL},
{"process_vm_writev", 6, NULL, NULL},

#endif /* !SYSENT_X86_64_H */
