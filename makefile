GCC = gcc -g

all: server

server: executioner.c executioner.h
	$(GCC) -g -o server executioner.c executioner.h server.c networking.c networking.h

client: executioner.c executioner.h
	$(GCC) -g -o client executioner.c executioner.h client.c networking.c networking.h

