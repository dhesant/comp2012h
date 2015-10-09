CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp List.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab04

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)