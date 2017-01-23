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
#include <pthread.h>
#include "server.h"

#define BUFSIZE 100

void process( char * s );
void sub_server( int sd );

// int main() {

//   // int x = 1;
//   // int f;
//   // int sd, connection;

//   // char buffer[MESSAGE_BUFFER_SIZE];

//   int sd = server_setup();
//   printf("Waiting to connect... \n");

//   // while (1) {
//   //   connection = server_connect( sd );
//   //   //printf("start game? (y/n)? ");
//   //   //fgets(buffer, sizeof(buffer), stdin);
//   //   // if (strchr(buffer, 'y')){
//   //   int pid = fork();
//   //   if ( pid == 0 ) {
//   //     close(sd);
//   //     sub_server( connection );
//   //     // printf("Reached this exit\n");
//   //     exit(0);
//   //   }        
//   //   else {
//   //     close( connection );
//   //   }
//   //   // }
//   // }
//   int newsockfd, portno, pid;
//   struct sockaddr_in serv_addr, cli_addr;
//   unsigned int clilen = sizeof(cli_addr);
//   char buffer[256];
  
//   listen(sd, 5);
//   while (1) {
//         newsockfd = accept(sd, (struct sockaddr *) &cli_addr, &clilen);
      
//         if (newsockfd < 0) {
//            printf("error on accept");
//            exit(1);
//         }
        
//         /* Create child process */
//         pid = fork();
      
//         if (pid < 0) {
//            printf("error on fork");
//            exit(1);
//         }
        
//         if (pid == 0) {
//            /* This is the client process */
//            close(sd);
//            sub_server(newsockfd);
//            exit(0);
//         }
//         else {
//            close(newsockfd);
//         }
      
//   } /* end of while */
//   return 0;
// }

void *connection_handler(void *);


      
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
