program_NAME := vect

program_SRCS := $(wildcard *.c)
program_OBJS := ${program_SRCS:.c=.o}

CC = gcc
CFLAGS += -std=c99 -Wall -g -pedantic

.PHONY: all clean distclean

all: $(program_NAME)

$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean

depend:
	makedepend -- $(CFLAGS) -- $(program_SRCS)
