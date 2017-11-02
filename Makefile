CC=g++
CFLAGS=-Wall -std=c++11

all: draw

draw: draw.o Screen.o Line.o Box.o Text.o TextBox.o
	$(CC) $(CFLAGS) -o $@ $^

draw.o: draw.cc Screen.h ScreenElement.h Line.h Box.h Text.h TextBox.h
	$(CC) $(CFLAGS) -c $<

Screen.o: Screen.cc Screen.h
	$(CC) $(CFLAGS) -c $<

Line.o: Line.cc Line.h ScreenElement.h Screen.h
	$(CC) $(CFLAGS) -c $<

Box.o: Box.cc Box.h Line.h ScreenElement.h Screen.h
	$(CC) $(CFLAGS) -c $<

Text.o: Text.cc Text.h ScreenElement.h Screen.h
	$(CC) $(CFLAGS) -c $<

TextBox.o: TextBox.cc TextBox.h Box.h Text.h ScreenElement.h Screen.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *~ *.o

clean-all: clean
	rm -rf draw

