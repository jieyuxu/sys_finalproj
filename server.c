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
  int sd, connection;

  sd = server_setup();
    
  while (x) {
    printf("Waiting to connect... \n");

    connection = server_connect( sd );
    int tpid;
    int stat = 0;
    int chpid = fork();
    if ( chpid == 0 ) {

      close(sd);
      sub_server( connection );
      printf("Reached this exit\n");
      x = 0;
      printf("CLOSING");
      close( connection );
    }
    else {
      do { 
         tpid = wait(&stat);
         printf("id %d\n", tpid);
         } while(tpid != -1);
      } 
  }
  x = 0;
  printf("END");
  exit(0);
  return 0;
}


void sub_server( int sd ) {
  Setup();
  Display();

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
