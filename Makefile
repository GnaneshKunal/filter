CC = gcc

CFLAGS = -g3 -O0 -fsanitize=undefined

SRCS = filter.c tree.c queue.c hash.c utils.c

OBJS = $(SRCS:.c=.o)

MAIN = filter

.PHONY: clean

TARGET = main

all: $(MAIN)
																		@echo Filter has been compiled

$(MAIN): $(OBJS)
																		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
																		$(CC) $(CFLAGS) -c $< -o $@

clean:
																		$(RM) *.o *~ $(MAIN)
