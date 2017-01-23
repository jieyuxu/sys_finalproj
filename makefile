GCC = gcc -c

all: selectserv selectclient

selectclient: selectclient.o networking.o executioner.o
	gcc -o client selectclient.o networking.o executioner.o

selectserv: selectserv.o networking.o executioner.o
	gcc -o server selectserv.o networking.o executioner.o

selectserv.o: executioner.c executioner.h networking.h selectserv.c 
	$(GCC) selectserv.c

selectclient.o: selectclient.c executioner.c executioner.h networking.h
	$(GCC) selectclient.c

networking.o: networking.c networking.h
	$(GCC) networking.c

executioner.o: executioner.c executioner.h
	$(GCC) executioner.c

clean:
	rm *.o
	rm *~