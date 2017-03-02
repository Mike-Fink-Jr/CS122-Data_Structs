CC = g++
CFLAGS = -g
OBJECTS = driver.o evaluate.o token.o tokenlist.o
evaluate:   $(OBJECTS)
	$(CC) -o evaluate $(OBJECTS)
	./evaluate

evaluate.o:	evaluate.cpp tokenlist.h
