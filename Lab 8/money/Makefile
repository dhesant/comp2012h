CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Money.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=money

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)