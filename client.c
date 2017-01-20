#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "networking.h"

int main( int argc, char *argv[] ) {

  char *host;
  if (argc != 2 ) {
    printf("host not specified, conneting to 127.0.0.1\n");
    host = "127.0.0.1";
  }
  else
    host = argv[1];
  
  int sd;

  sd = client_connect( host );

  //read( sd, buffer, sizeof(buffer) );
  
  char buffer[MESSAGE_BUFFER_SIZE];

  //Reading for Setup
  read( sd, buffer, sizeof(buffer) );
  setPuzzle(buffer);
  
  
  while (1) {
    Display();
    printf("Enter Letter: ");
    fgets( buffer, sizeof(buffer), stdin );
    char *p = strchr(buffer, '\n');
    *p = 0;

    if(Player_Input(buffer)){
    
      write( sd, buffer, sizeof(buffer) );
      read( sd, buffer, sizeof(buffer) );
      //printf( "received: %s\n", buffer );
    }
    
  }
  
  return 0;
}
