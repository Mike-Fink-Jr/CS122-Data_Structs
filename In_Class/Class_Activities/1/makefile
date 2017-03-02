# A sample makefile, which not only compiles the programs
# but runs them afterwards.  Most makefiles would not include
# the running step afterwards, but doing so here saves a little
# bit of time during code development.

# Make sure we use the correct complier
CC = g++

test1:	test1.o sum.o

test2:	test2.o sum.o

test:	test1 test2
	./test1
	./test2
