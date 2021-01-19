PROG := bogomips
SRCS := bogomips.c

CC      := cc
CFLAGS  := -O2 -Wall 
LDFLAGS :=

OBJS   = $(SRCS:.c=.o)
DEPS   = $(SRCS:.c=.d)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) *~

cleaner: clean
	rm -rf $(PROG)
