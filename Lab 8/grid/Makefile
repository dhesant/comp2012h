CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp grid3d.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=grid3d

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)