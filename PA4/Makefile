CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main2.cpp bigint.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bigint

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
