# Variables
CC = gcc
CFLAGS = -Wall -Wextra -I. $(shell pkg-config --cflags json-c)
LDFLAGS = $(shell pkg-config --libs json-c)
TARGET = sshtool
SRCS = main.c actions.c database.c menus.c
OBJS = $(SRCS:.c=.o)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
