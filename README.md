strace
======

This is a lighweight version of the well-known syscall tracer.

It runs under Linux on i386 and x86_64.

Compilation
===========
~~~bash
$ make
~~~
To force 32 bits mode :
~~~bash
$ make m32=1
~~~

Usage
=====
~~~bash
$ ./strace 
usage: ./strace (-p pid | command [arg ...])
~~~

Create and trace a new process :
~~~bash
$ ./strace ls /dev/
...
~~~

Or attach to one which is already running :
~~~bash
$ ./strace -p $(pidof foobar)
...
~~~
