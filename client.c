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
<<<<<<< HEAD
  // setPuzzle(buffer);
  printf("the buffer: %s\n", buffer);

  char * cat = "cat";
  
  while (1) {
    Display(cat);
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
=======
  printf("<%s>\n", buffer);

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
     
>>>>>>> 238d27c576843467a72709d1f9dbe4552312fc3a
  
  return 0;
}
