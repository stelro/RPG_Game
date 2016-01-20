#Makefile
#This file is part of countme
#Stelmach Ro <stelmach.ro@gmail.com>

TARGET = sdlgame
CC = g++
CFLAGS = -g -std=c++11 `sdl2-config --cflags --libs`

.PHONY: default all clean

default: $(TARGET)
all:default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
