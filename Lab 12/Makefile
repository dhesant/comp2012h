CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp func.cpp exp_func.cpp impulse_func.cpp poly_func.cpp tri_func.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=func

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
