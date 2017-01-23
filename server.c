#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "executioner.h"
#include <sys/socket.h>
#include "networking.h"
#include <sys/types.h>
#include <netinet/in.h>

void process( char * s );
void sub_server( int sd );

int main() {

  int x = 1;
  int f;
  int sd, connection;

  char buffer[MESSAGE_BUFFER_SIZE];

  sd = server_setup();
  printf("Waiting to connect... \n");

  while (1) {
    connection = server_connect( sd );
    //printf("start game? (y/n)? ");
    //fgets(buffer, sizeof(buffer), stdin);
    // if (strchr(buffer, 'y')){
    int pid = fork();
    if ( pid == 0 ) {
      close(sd);
      sub_server( connection );
      printf("Reached this exit\n");
    }        
    else {
      close( connection );
    }
    // }
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
  

// void process( char * s ) {
  
//   while ( *s ) {
//     *s = (*s - 'a' + 13) % 26 + 'a';
//     s++;
//   }
  
  
// }
