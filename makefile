GCC = gcc -c

all: selectserv selectclient

selectclient: client.o networking.o executioner.o
	gcc -o client client.o networking.o executioner.o

selectserv: selectserv.o networking.o executioner.o
	gcc -o server selectserv.o networking.o executioner.o

selectserv.o: executioner.c executioner.h networking.h selectserv.c server.c server.h
	$(GCC) selectserv.c 

client.o: client.c executioner.c executioner.h networking.h
	$(GCC) client.c

networking.o: networking.c networking.h
	$(GCC) networking.c

executioner.o: executioner.c executioner.h
	$(GCC) executioner.c

clean:
	rm *.o
	rm *~
