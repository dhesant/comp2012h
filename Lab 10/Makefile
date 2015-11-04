CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=merge.cpp Array.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=array

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
