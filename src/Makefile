CC=g++
CFLAGS=-std=c++11 -O1 -Wall -Werror
TOP=..
TARGET=$(TOP)/bin/geo_distance
LIBS=

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.cpp geo_distance.cpp
	mkdir -p "$$(dirname $(TARGET))"
	$(CC) $(CFLAGS) $^ -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)

