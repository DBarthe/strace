
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

SRC = $(wildcard $(SRCPATH)/*.c)
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
