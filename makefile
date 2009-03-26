CFLAGS = -c -Wall -g -ansi -pedantic
LFLAGS = -lm -lSDL
SOURCES = main.c at.c
OBJ = $(SOURCES:.c=.o)
CC = gcc
EXE = sandbox

all: $(EXE) $(SOURCES)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *~

purge:
	rm -rf *.o *~ $(EXE)
