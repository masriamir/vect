NAME := vect

SRCS := $(wildcard src/*.c)
OBJS := ${SRCS:.c=.o}

INCS = -I./include

CC = gcc
CFLAGS = -std=c99 -Wall -g -pedantic

.PHONY: all clean distclean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@- $(RM) $(NAME)
	@- $(RM) $(OBJS)

distclean: clean

depend: $(SRCS)
	makedepend $(INCS) $^
