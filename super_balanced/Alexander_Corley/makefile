CC=g++
CFLAGS=-c -g -std=c++11
SOURCES=main.cpp tree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=super_balanced

make_all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
