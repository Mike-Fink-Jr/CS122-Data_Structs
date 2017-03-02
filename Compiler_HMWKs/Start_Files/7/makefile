CC = g++
CFLAGS = -g
OBJECTS = driver.o compile.o machine.o vartree.o exprtree.o token.o tokenlist.o 
comrun:	$(OBJECTS)
	$(CC) -o comrun $(OBJECTS)
	./comrun sample

compile.o:	evaluate.cpp machine.h tokenlist.h vartree.h exprtree.h funmap.h

exprtree.o:	exprtree.cpp machine.h tokenlist.h vartree.h exprtree.h funmap.h

machine.o:	machine.cpp machine.h
