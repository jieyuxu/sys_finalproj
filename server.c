#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "executioner.h"

#include "networking.h"

void process( char * s );
void sub_server( int sd );

int main() {

  int x = 1;
  int f;
  int sd, connection;

  char buffer[MESSAGE_BUFFER_SIZE];

  sd = server_setup();
  printf("Waiting to connect... \n");

  while (x) {

    connection = server_connect( sd );

    printf("start game? (y/n)? ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("%s\n", buffer);

    if (strchr(buffer, 'y')){
      f = fork();
      if ( f == 0 ) {
          close(sd);
          sub_server( connection );
          printf("Reached this exit\n");
          x = 0;
      }
      
      else {
        close( connection );
      }
    }
    
    
  }
  return 0;
}


void sub_server( int sd ) {
  Setup();
  Display();
  write(sd, _PUZZLE, sizeof(_PUZZLE));
  
  char buffer[MESSAGE_BUFFER_SIZE];
  
  while ( checkWin()){
    
    read( sd, buffer, sizeof(buffer));
    printf("[SERVER %d] received: %s\n", getpid(), buffer );
    Player_Input( buffer );
    Display();
    write( sd, buffer, sizeof(buffer));    
  }   
}
  

void process( char * s ) {
  /*
  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
  */
  
}
