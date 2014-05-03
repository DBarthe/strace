
CC ?= gcc

INCPATH = ./include
SRCPATH = ./src

CFLAGS = -I $(INCPATH) -Wall -Wextra
DBGFLAGS = -ggdb3 -DDEBUG
NDBGFLAGS = -DNDEBUG
OFLAGS = -O3
LDFLAGS =

SRC = $(wildcard $(SRCPATH)/*.c)
OBJ = $(SRC:.c=.o)

RM = rm -vf

TARGET := strace

ifeq ($(DEBUG), 1)
CFLAGS += $(DBGFLAGS)
else
CFLAGS += $(NDBGFLAGS) $(OFLAGS)
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
