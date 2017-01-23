#ifndef SERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "executioner.h"
#include <sys/socket.h>
#include "networking.h"
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>


void process( char * s );
void sub_server( int sd );

#endif
