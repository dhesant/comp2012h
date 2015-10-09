CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp date.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=date

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
