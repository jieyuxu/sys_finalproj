GCC = gcc -g

all: executioner.o

executioner.o: executioner.c executioner.h
	$(GCC) -g executioner.c