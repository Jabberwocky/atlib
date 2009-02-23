CFLAGS = -c -Wall -g -I./include/
DIR = src/
SOURCES = $(DIR)at_color.cpp $(DIR)at_core.cpp \
$(DIR)at_event.cpp $(DIR)at_font.cpp $(DIR)at_window.cpp

OBJ = $(SOURCES:.cpp=.o)
CC = g++

AR = ar cr
ARNAME = lib/libat.a

all: $(ARNAME) $(SOURCES)

$(ARNAME): $(OBJ)
	$(AR) $(ARNAME) $(OBJ) $(LFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(DIR)*.o $(DIR)*~

purge:
	rm -rf $(DIR)*.o $(DIR)*~ $(ARNAME)
