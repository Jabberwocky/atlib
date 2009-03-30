EXDIR = examples/
ATDIR = atlib/

CFLAGS = -c -Wall -g -ansi -pedantic -I./atlib
LFLAGS = -lm -lSDL
CC = gcc

all: $(ATDIR)at.o $(EXDIR)ex1 $(EXDIR)ex2 $(EXDIR)ex3

$(ATDIR)at.o:
	$(CC) $(ATDIR)at.c $(CFLAGS) -o $(ATDIR)at.o

$(EXDIR)ex1: $(EXDIR)ex1.o
	$(CC) $(EXDIR)ex1.o $(ATDIR)at.o $(LFLAGS) -o $(EXDIR)ex1

$(EXDIR)ex1.o:
	$(CC) $(EXDIR)ex1.c $(CFLAGS) -o $(EXDIR)ex1.o
	
$(EXDIR)ex2: $(EXDIR)ex2.o
	$(CC) $(EXDIR)ex2.o $(ATDIR)at.o $(LFLAGS) -o $(EXDIR)ex2

$(EXDIR)ex2.o:
	$(CC) $(EXDIR)ex2.c $(CFLAGS) -o $(EXDIR)ex2.o

$(EXDIR)ex3: $(EXDIR)ex3.o
	$(CC) $(EXDIR)ex3.o $(ATDIR)at.o $(LFLAGS) -o $(EXDIR)ex3

$(EXDIR)ex3.o:
	$(CC) $(EXDIR)ex3.c $(CFLAGS) -o $(EXDIR)ex3.o

clean:
	rm -rf $(EXDIR)*.o $(EXDIR)*~ $(ATDIR)*.o $(ATDIR)*.o
