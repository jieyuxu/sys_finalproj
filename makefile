GCC = gcc -c

all: server client

client: client.o networking.o executioner.o
	gcc -o client client.o networking.o executioner.o

server: server.o networking.o executioner.o
	gcc -o server server.o networking.o executioner.o

server.o: executioner.c executioner.h networking.h server.c 
	$(GCC) server.c

client.o: client.c executioner.c executioner.h networking.h
	$(GCC) client.c

networking.o: networking.c networking.h
	$(GCC) networking.c

executioner.o: executioner.c executioner.h
	$(GCC) executioner.c