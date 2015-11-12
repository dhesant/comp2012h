# Add more object files here..
# make will help your build all the object files..

OBJS = Stack.o switchbox.o
CC = g++
CFLAGS = -Wall
TARGET = switchbox

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGET)

