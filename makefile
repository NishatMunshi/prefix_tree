TARGET ?= main.exe
SRC_DIRS ?=

SRCS := $(shell ls $(SRC_DIRS) *.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))

CC = gcc
CSTD = c2x
CFLAGS = -std=$(CSTD) -Wall -Wextra -Wunused -Werror -pedantic -ggdb -fdiagnostics-color=always
RM = rm -f

# compile:
$(TARGET): $(OBJS)

# link:
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBES) $(LDLIBS)

# clean:
	$(RM) $(OBJS) $(DEPS)

clean:
	rm -f *.o 
	rm main.exe