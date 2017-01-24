#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "networking.h"

int main( int argc, char *argv[] ) {
  
  //title(); //displays title
  char *host;
  
  if (argc != 2 ) {
    printf("host not specified, conneting to 127.0.0.1\n");
    host = "127.0.0.1";
  }
  else
    host = argv[1];

  int sd;

  sd = client_connect( host );                                                                                                                                                                  

  char buffer[MESSAGE_BUFFER_SIZE];
  
  //Reading for Setup
  printf("Reading for input 1\n");
  read( sd, buffer, sizeof(buffer) );
  setPuzzle(buffer);
  //printf("The word is: %s", buffer);
  
  
  

  while (checkWin()) {
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
