CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=PA5.cpp Game.cpp Animal.cpp Dog.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=animalgame

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
