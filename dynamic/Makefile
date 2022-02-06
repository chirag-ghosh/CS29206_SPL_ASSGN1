SHELL = /bin/sh
CC    = gcc
FLAGS        = -std=gnu99 -Iinclude
CFLAGS       =  -g -Wall -Wextra -ggdb3 -shared
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET  = chirag.so
SOURCES = $(shell echo *.c)
HEADERS = $(shell echo *.h)
OBJECTS = $(SOURCES:.c=.o)

LIBDIR = /usr/local/lib
INCLUDEDIR = /usr/include

all: $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

install: $(TARGET)
	cp $(TARGET) $(LIBDIR)
	cp $(HEADERS) $(INCLUDEDIR)

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)