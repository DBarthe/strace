
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>


#include "tracer.h"
#include "utils.h"

static void exec_tracee(char const* progname, char **av, char **env)
{
  (void)env;
  ptrace(PTRACE_TRACEME, 0, 0, 0);
  raise(SIGSTOP);

  //  sleep(20);

  execvp(progname, av);
 }


/* static void syscall_info(pid_t child_pid, bool in_syscall, struct user_regs_struct *regs) */
/* { */
/*   (void)child_pid; */
/*   if (in_syscall == false) */
/*     { */
/*       fprintf(stderr, "syscall info: scno=%ld\n", regs->rax); */
/*     } */
/*   else */
/*     { */
/*       long int ret = (long int)regs->rax; */
/*       if (ret < 0) */
/* 	fprintf(stderr, "syscall info: ret=-1 errno=%ld, %s\n", -ret, strerror(-ret)); */
/*       else */

/* 	fprintf(stderr, "syscall info: ret=%ld(0x%lx)\n", ret, ret); */
/*     } */
/* } */


static pid_t	wait_tracees(t_tracer *tracer, int *status)
{
  pid_t		pid;

  pid = waitpid(-1, status, __WALL);
  if (pid <= 0)
    {
      if (errno == EINTR)
	return (0);
      if (errno == ECHILD && tracer->nprocs == 0)
	return (-1);
      perror_die("waitpid");
    }
  return (pid);
}

static void	treat_breakpoint(t_tracer *tracer, t_tracee *tracee)
{
  struct user_regs_struct regs;
  long int ins;

  if (ptrace(PTRACE_GETREGS, tracee->pid, 0, &regs) < 0)
    {
      if (errno == ESRCH)
	return ;
      perror_die("ptrace");
    }

  ins = ptrace(PTRACE_PEEKTEXT, tracee->pid, regs.rip, 0);
  if (is_in_syscall(tracee) || (ins & 0xffff) == 0x050f
      || (ins & 0xffff) == 0x80cd)
    {
      fprintf(stderr, "%p: %02lx %02lx %02lx %02lx %02lx "
	      "%02lx %02lx %02lx\n",
	      (void *)regs.rip,
	      ins & 0xff,
	      (ins >> 8) & 0xff,
	      (ins >> 16) & 0xff,
	      (ins >> 24) & 0xff,
	      (ins >> 32) & 0xff,
	      (ins >> 40) & 0xff,
	      (ins >> 48) & 0xff,
	      (ins >> 56) & 0xff);

      fprintf(stderr, "# syscall-%s-stop detected ... ",
	      is_in_syscall(tracee)? "exit" : "enter");
      if (is_in_syscall(tracee))
	tracee->flags &= ~TRACEE_INSYSCALL;
      else
	tracee->flags |= TRACEE_INSYSCALL;
    }

  if (ptrace(PTRACE_SINGLESTEP, tracee->pid, 0, 0) < 0)
    {
      DEBUG_PRINT("ptrace return -1");
    }
}

static void	treat_ptrace_stop(t_tracer *tracer, t_tracee *tracee,
				  int status)
{
  int		signal;

  if (WIFEXITED(status))
    {
      fprintf(stderr, "Program exited with return code: %d\n",
	      WEXITSTATUS(status));
      tracee_cleanup(tracee);
      tracer->nprocs--;
    }
  else if (WIFSIGNALED(status))
    {
      fprintf(stderr, "+++ killed by %d+++\n", WTERMSIG(status));
      tracee_cleanup(tracee);
      tracer->nprocs--;
    }
  else if (!WIFSTOPPED(status))
    {
      fprintf(stderr, "PANIC WIFSTOPPED(status) == false\n");
    }

  else
    {
      signal = WSTOPSIG(status);

      if (signal == SIGSTOP && (tracee->flags & TRACEE_IGNORE_ONE_STOP))
	{
	  fprintf(stderr, "ignore one sigstop\n");
	  tracee->flags &= ~TRACEE_IGNORE_ONE_STOP;
	  signal = 0;
	}
      else if (signal != SIGTRAP)
	{
	  siginfo_t si;
	  if (ptrace(PTRACE_GETSIGINFO, tracee->pid, 0, &si) < 0)
	    {
	      fprintf(stderr, "group-stop detected | signal = %d\n", signal);
	    }
	  else
	    {
	      fprintf(stderr, "signal-delivery-stop detected | signal = %d\n",
		      signal);
	    }
	}
      else
	{
	  treat_breakpoint(tracer, tracee);
	  return ;
	}

      if (ptrace(PTRACE_SINGLESTEP, tracee->pid, 0, signal) < 0)
	{
	  DEBUG_PRINT("ptrace return -1");
	}
    }
}

static void	trace(t_tracer *tracer)
{
  pid_t		pid;
  int		status;
  t_tracee	*tracee;
  int		signal;

  while ((pid = wait_tracees(tracer, &status)) >= 0)
    {
      if (pid == 0)
	continue;
      if ((tracee = tracees_tab_get(&tracer->trtab, pid)) == NULL)
	{
	  if (!WIFSTOPPED(status))
	    {
	      fprintf(stderr, "exit of unknown pid %u seen\n", pid);
	      continue;
	    }
	  else
	    {
	      fprintf(stderr, "stop of unknown pid %u seen, PTRACE_CONTed it",
		      pid);
	      ptrace(PTRACE_CONT, pid, 0, 0);
	      continue;
	    }
	}

      treat_ptrace_stop(tracer, tracee, status);
    }
}

/* static void trace2(t_tracer *tracer) */
/* { */
/*   bool ignore_one_sigstop = true; */
/*   bool in_syscall = false; */
/*   int status = 0; */

/*   /\* waitpid(child_pid, &status, __WALL); *\/ */

/*   /\* ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_TRACESYSGOOD); *\/ */

/*   /\* ptrace(ptrace_restart, child_pid, 0, 0); *\/ */

/*   while (42) */
/*     { */
/*       pid_t wait_ret = waitpid(child_pid, &status, __WALL); */

/*       // waitpid errors */
/*       if (wait_ret < 0) */
/* 	{ */
/* 	  if (errno == EINTR) */
/* 	    continue; */
/* 	  if (errno == ECHILD && tracer->trtab.size == 0) */
/* 	    break; */
/* 	  fprintf(stderr, "waitpid fatal error : %s\n", strerror(errno)); */
/* 	  exit(EXIT_FAILURE); */
/* 	} */

    /*   // tracee exit */
    /*   if (WIFEXITED(status)) */
    /* 	{ */
    /* 	  fprintf(stderr, "Program exited with return code: %d\n", WEXITSTATUS(status)); */
    /* 	  break; */
    /* 	} */

    /*   killed by signal */
    /*   if (WIFSIGNALED(status)) */
    /* 	{ */
    /* 	  fprintf(stderr, "+++ killed by %d+++\n", WTERMSIG(status)); */
    /* 	  break; */
    /* 	} */

    /*   problem with child */
    /*   if (!WIFSTOPPED(status)) */
    /* 	{ */
    /* 	  fprintf(stderr, "PANIC WIFSTOPPED(status) == false\n"); */
    /* 	  break; */
    /* 	} */

    /*   else ... */

    /*   get registers */
      /* struct user_regs_struct regs; */
      /* if (ptrace(PTRACE_GETREGS, child_pid, 0, &regs) < 0) */
      /* 	{ */
      /* 	  if (errno == ESRCH) */
      /* 	    continue; */
      /* 	  fprintf(stderr, "ptrace error : %s\n", strerror(errno)); */
      /* 	  break; */
      /* 	} */


    /*   get signal */
    /*   int signal = WSTOPSIG(status); */

    /*   ignore one sigstop */
    /*   if (signal == SIGSTOP && ignore_one_sigstop) */
    /* 	{ */
    /* 	  fprintf(stderr, "ignore one sigstop\n"); */
    /* 	  ignore_one_sigstop = false; */
    /* 	  signal = 0; */
    /* 	} */

    /*   // simple single step */
    /*   else if (signal == SIGTRAP) */
    /*   	{ */
    /*   	  //fprintf(stderr, "single-step\n"); */
    /*   	  signal = 0; */
    /*   	} */

    /*   not a break-point */
    /*   else if (signal != SIGTRAP) */
    /* 	{ */
    /* 	  siginfo_t si; */
    /* 	  if (ptrace(PTRACE_GETSIGINFO, child_pid, 0, &si) < 0) */
    /* 	    { */
    /* 	      fprintf(stderr, "group-stop detected | signal = %d\n", signal); */
    /* 	    } */
    /* 	  else */
    /* 	    { */
    /* 	      fprintf(stderr, "signal-delivery-stop detected | signal = %d\n", signal); */
    /* 	    } */
    /* 	} */
    /*   syscall */
    /*   else */
    /* 	{ */
    /* 	  get instruction */
    	/*   long int ins = 0; */
    	/*   ins = ptrace(PTRACE_PEEKTEXT, child_pid, regs.rip, 0); */
    	/*   if (in_syscall || (ins & 0xffff) == 0x050f || (ins & 0xffff) == 0x80cd) */
    	/*     { */
    	/*       fprintf(stderr, "%p: %02lx %02lx %02lx %02lx %02lx %02lx %02lx %02lx\n", (void *)regs.rip, */
    	/* 	      ins & 0xff, */
    	/* 	      (ins >> 8) & 0xff, */
    	/* 	      (ins >> 16) & 0xff, */
    	/* 	      (ins >> 24) & 0xff, */
    	/* 	      (ins >> 32) & 0xff, */
    	/* 	      (ins >> 40) & 0xff, */
    	/* 	      (ins >> 48) & 0xff, */
    	/* 	      (ins >> 56) & 0xff); */


    	/*       fprintf(stderr, "# syscall-%s-stop detected ... ", in_syscall ? "exit" : "enter"); */
    	/*       syscall_info(child_pid, in_syscall, &regs); */
    	/*       in_syscall ^= true; */
    	/*     } */
    	/*   signal = 0; */
    	/* } */

    /*   if (ptrace(ptrace_restart, child_pid, 0, signal) < 0) */
    /* 	{ */
    /* 	  break; */
    /* 	} */
    /* } */

/* } */

int		main(int ac, char **av, char **env)
{
  t_tracer	tracer;
  pid_t		child_pid;
  t_tracee	*tracee;

  if (ac < 2)
    return EXIT_FAILURE;
  tracer_ctor(&tracer);
  child_pid = fork();
  if (child_pid < 0)
    die("fork");
  if (child_pid == 0)
    {
      exec_tracee(av[1], av + 1, env);
      fprintf(stderr, "execve has failed: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

  tracee = tracees_tab_new_entry(&tracer.trtab);

  tracee->pid = child_pid;
  tracee->flags = TRACEE_IGNORE_ONE_STOP;
  tracer.nprocs = 1;

  trace(&tracer);
  return EXIT_SUCCESS;
}
