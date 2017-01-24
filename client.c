#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "executioner.h"
#include "networking.h"

int main( int argc, char *argv[] ) {

  char *host;
  if (argc != 2 ) {
    printf("host not specified, connecting to 127.0.0.1\n");
    host = "127.0.0.1";
  }
  else
    host = argv[1];
  
  int sd;

  sd = client_connect( host );

  char buffer[MESSAGE_BUFFER_SIZE];


  //Reading for Setup
  read( sd, buffer, sizeof(buffer) );
  // setPuzzle(buffer);
  printf("the buffer: %s\n", buffer);
  
  while (1) {
    printf("where you at 5\n");
    Display(buffer);
    printf("Enter Letter: ");
    fgets( buffer, sizeof(buffer), stdin );
    char *p = strchr(buffer, '\n');
    *p = 0;
    send(sd, buffer, 200, 0);

   // printf("where you at 1\n");
    //Player_Input(buffer, cat);

    // if(Player_Input(buffer, cat)){
    //   //printf("where you at 2\n");
    //   write( sd, buffer, sizeof(buffer) );
    //  // printf("where you at 3\n");
    //   read( sd, buffer, sizeof(buffer) );
    //   //printf( "received: %s\n", buffer );
    //   //printf("where you at 4\n");
    // }
    
  }
  
  return 0;
}
