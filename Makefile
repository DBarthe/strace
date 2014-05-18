##
## Makefile for strace in /home/bade/Dev/tek2/Unix+/AUSP_strace
## 
## Made by Barthelemy Delemotte
## Login   <bade@epitech.net>
## 
## Started on Sun May 18 17:00:17 2014 Barthelemy Delemotte
## Last update Sun May 18 17:04:49 2014 Barthelemy Delemotte
##

DEBUG ?= 0
m32 ?= 0

CC ?= gcc

INCPATHS = ./include ./generated
SRCPATH = ./src

INCLUDES = $(foreach dir,$(INCPATHS),-I $(dir))

CFLAGS = -Wall -Wextra $(INCLUDES)
DBGFLAGS = -ggdb3 -DDEBUG
NDBGFLAGS = -DNDEBUG
OFLAGS = -O3
LDFLAGS =

SRC = 	src/print_args.c \
	src/utils.c \
	src/proc.c \
	src/proclist.c \
	src/print.c \
	src/exec.c \
	src/status.c \
	src/wait.c \
	src/attach.c \
	src/signals_tab.c \
	src/registers.c \
	src/tracer.c \
	src/tracee.c \
	src/syscall.c \
	src/sc_print_default.c \
	src/options.c \
	src/main.c \
	src/sc_print.c \
	src/strace.c \
	src/sc_table.c \
	src/analyse.c \
	src/errno_tab.c \
	src/exit.c

OBJ = $(SRC:.c=.o)

RM = rm -vf

TARGET := strace

ifeq ($(DEBUG), 1)
CFLAGS += $(DBGFLAGS)
else
CFLAGS += $(NDBGFLAGS) $(OFLAGS)
endif

ifeq ($(m32), 1)
CFLAGS += -m32
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
