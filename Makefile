CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11 -Iinclude
TARGET := build/cinema_sessions

SRCS := src/main.c src/movies.c src/sessions.c src/io_validation.c
OBJS := $(patsubst src/%.c,build/%.o,$(SRCS))

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS) | build
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c -o $@ $<

build:
	mkdir -p build

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build
