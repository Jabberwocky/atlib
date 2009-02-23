CFLAGS = -c -Wall -g -I../include/
LFLAGS = -L../lib/ -lat -lSDL
SOURCES = main.cpp
OBJ = $(SOURCES:.cpp=.o)
CC = g++
EXE = at

all: $(EXE) $(SOURCES)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

purge:
	rm -rf *~ *.o $(EXE)
